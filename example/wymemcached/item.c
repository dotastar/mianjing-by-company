/*
 * support following operation:
 * 1. store cmd: set add replace append prepend 
 * 2. read cmd: get
 * 3. stat cmd: stat
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "slab.h" 
#include "item.h"


const int MAX_KEY_LEN = 256;
const int MAX_VALUE_LEN = 1024*1024;
const int DEFAULT_HASHTABLE_SIZE = 1<<16;

typedef struct {
	item ** ht;
	int ht_size;
	int item_count;
} hashtable;

static hashtable g_hashtable;
static item *g_lru_head[200];
static item *g_lru_tail[200];

item* item_get_item(void *p_key, int key_len){
	//fprintf(stdout, "item_get_item(%s)\n", (char *)p_key);
	uint32_t h = hash((uint8_t *)p_key, key_len);
	h %= DEFAULT_HASHTABLE_SIZE;
	item *it = g_hashtable.ht[h];

	while(it != NULL){
		//fprintf(stdout, "item_get_item check %p for hash %u\n", it, h);

		if(key_len == it->key_len && memcmp(p_key, it->data, key_len) == 0){
			return it;
		} else {
			it = it->ht_next;
		}
	}
	return NULL;
}

bool item_replace(void *p_key, int key_len, void *p_new_value, int new_value_len){
	//fprintf(stdout, "[debug]item_replace(%s)\n", (char *)p_key);
	item *it = item_get_item(p_key, key_len);
	if(it == NULL){
		return false;
	}
	uint8_t *p_old_value = (uint8_t *)it->data + it->key_len;
	int old_value_len = it->value_len;

	int new_value_class_id = slab_find_class(sizeof(item)+key_len+old_value_len);
	int old_value_class_id = slab_find_class(sizeof(item)+key_len+new_value_len);
	if(new_value_class_id == old_value_class_id){
		memcpy(p_old_value, p_new_value, new_value_len);
		return true;
	}else {
		uint32_t h = hash((uint8_t *)p_key, key_len);
		h %= DEFAULT_HASHTABLE_SIZE;
		item* head= g_hashtable.ht[h];
		item* p = head;
		
		item *prev = NULL;
		while(p!= NULL){
		if(key_len == p->key_len && memcmp(p_key, p->data, key_len) == 0){
			if(p->ht_next == NULL || prev == NULL){
				g_hashtable.ht[h] = p->ht_next;
			}
			else{
				prev->ht_next = p->ht_next;
			} 
			break;
		} else {
			prev = p;
			p = p->ht_next;
		}
		}
		
		if(it == g_lru_head[it->slab_class]){
			if(it->lru_next == NULL){
				g_lru_head[it->slab_class] = g_lru_tail[it->slab_class] = NULL;
			} else {
				it->lru_next->lru_prev = NULL;
				g_lru_head[it->slab_class] = it->lru_next;
			}
		} else {
			if(it == g_lru_tail[it->slab_class]){
				it->lru_prev->lru_next = NULL;
				g_lru_tail[it->slab_class] = it->lru_prev;
			} else {
				it->lru_prev->lru_next = it->lru_next;
				it->lru_next->lru_prev = it->lru_prev;
				}
		}
		slab_free(it);
		return item_add(p_key, key_len, p_new_value, new_value_len);
	}
}

bool item_add(void *p_key, int key_len, void *p_value, int value_len){
	//fprintf(stdout, "[debug]item_add(%s)\n", (char *)p_key);
	item *it = item_get_item(p_key, key_len);
	if(it != NULL){
		fprintf(stdout, "item_add(%s) exsited\n", (char *)p_key);
		return false;
	}
	it = slab_alloc(sizeof(item)+key_len+value_len);
	if(it == NULL){
		fprintf(stdout, "[debug]item_add(%s) full, need free from tail\n", (char *)p_key);
		int slab_class = slab_find_class(sizeof(item)+key_len+value_len);
		item *p = g_lru_tail[slab_class];
		if(p == NULL){
			printf("[error] no more item can release;");
			return false;
		} else {
			if(p == g_lru_head[slab_class]){
				g_lru_head[slab_class] = NULL;
				g_lru_tail[slab_class] = NULL;
			} else {
			if(p->lru_prev != NULL) p->lru_prev->lru_next = p->lru_next;
			if(p->lru_next != NULL) p->lru_next->lru_prev = p->lru_prev;
			g_lru_tail[slab_class] = p->lru_prev;
			}
		}
		slab_free(p);
		it = slab_alloc(sizeof(item)+key_len+value_len);
		if(it == NULL){
			printf("[error] no more item can alloc");
			return false;
		}
	}
	it->key_len = key_len;
	it->value_len = value_len;
	memcpy(it->data, p_key, key_len);
	memcpy(it->data+key_len, p_value, value_len);
	// add to ht
	uint32_t h = hash((uint8_t *)p_key, key_len);
	h %= DEFAULT_HASHTABLE_SIZE;
	it->ht_next = g_hashtable.ht[h];
	g_hashtable.ht[h] = it;
	//fprintf(stdout, "item_add add %p for hash %u\n", g_hashtable.ht[h], h);
	//add to lru
	if(g_lru_head[it->slab_class] == NULL){
		it->lru_next = NULL;
		it->lru_prev = NULL;
		g_lru_head[it->slab_class] = it;
		g_lru_tail[it->slab_class] = it;
	} else {
		it->lru_prev = NULL;
		it->lru_next = g_lru_head[it->slab_class];
		it->lru_next->lru_prev = it;
		g_lru_head[it->slab_class] = it;
	}
	return true;
}

bool item_set(void *p_key, int key_len, void *p_value, int value_len){
	//fprintf(stdout, "[debug]item_set(%s)\n", (char *)p_key);
	if(item_get_item(p_key, key_len) != NULL){
		return item_replace(p_key, key_len, p_value, value_len);
	} else {
		return item_add(p_key, key_len, p_value, value_len);
	}
}


bool item_get(void *p_key, int key_len, void **pp_value, int *p_value_len){
	//fprintf(stdout, "[debug]item_get(%s)\n", (char *)p_key);
	item *it = item_get_item(p_key, key_len);
	if(it == NULL){
		return false;
	} else {
			*pp_value = it->data + key_len;
			*p_value_len = it->value_len;
			//move to LRU head
			if(it != g_lru_head[it->slab_class]){
				if(it == g_lru_tail[it->slab_class]){
					it->lru_prev->lru_next = NULL;
					g_lru_tail[it->slab_class] = it->lru_prev;
				} else {
				it->lru_prev->lru_next = it->lru_next;
				it->lru_next->lru_prev = it->lru_prev;
				}
				it->lru_next = g_lru_head[it->slab_class];
				it->lru_next->lru_prev = it;
				it->lru_prev = NULL;
				g_lru_head[it->slab_class] = it;
			}
		return true;
	}
}

void	init_hashtable(){
	g_hashtable.ht_size = DEFAULT_HASHTABLE_SIZE;
	g_hashtable.item_count = 0;
	g_hashtable.ht = (item **)malloc(g_hashtable.ht_size * sizeof(item *));
	memset(g_hashtable.ht, 0, g_hashtable.ht_size * sizeof(item *));
}
