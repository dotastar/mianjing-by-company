#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>

/*
 * a chunk = struct item + key + value 
 */
 typedef struct item_{
	struct item_ * lru_prev;
	struct item_ * lru_next;
	struct item_ * ht_next;
	int slab_class;
	int key_len;
	int value_len;
	char data[];
} item;

bool item_replace(void *p_key, int key_len, void *p_new_value, int new_value_len);
bool item_add(void *p_key, int key_len, void *p_value, int p_value_len);
bool item_set(void *p_key, int key_len, void *p_value, int value_len);
bool item_get(void *p_key, int key_len, void **pp_value, int *p_value_len);
void	init_hashtable();
void 	init_lru();

#endif