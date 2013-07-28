#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "item.h"
#include "slab.h"

typedef struct {
	int total_count;
	int free_count;
	int item_size;
	item **free_list;
} slab_head;
typedef struct {
	int pool_size;
	int pool_remain_size;
	uint8_t *pool_base_ptr;
	uint8_t *pool_current_ptr;
	int slab_class_max_count;
	double factor;
	int smallest_size;
	int biggest_size;
	int class_count;
	slab_head *slab_base;
} slab;
slab g_slab;
int slab_add_page(int class_id)
{
	if(g_slab.pool_remain_size < g_slab.biggest_size) return -1;
	int new_count = g_slab.biggest_size/g_slab.slab_base[class_id].item_size;
	g_slab.slab_base[class_id].total_count += new_count;
	g_slab.slab_base[class_id].free_list = realloc(g_slab.slab_base[class_id].free_list, g_slab.slab_base[class_id].total_count * sizeof(void *));
	for(int j = g_slab.slab_base[class_id].free_count; j < g_slab.slab_base[class_id].free_count + new_count; ++j) {
		g_slab.slab_base[class_id].free_list[j] = (item *)g_slab.pool_current_ptr;
		memset(g_slab.slab_base[class_id].free_list[j], 0, g_slab.slab_base[class_id].item_size);
		g_slab.slab_base[class_id].free_list[j]->slab_class = class_id;
		g_slab.pool_current_ptr += g_slab.slab_base[class_id].item_size;
		g_slab.pool_remain_size -= g_slab.slab_base[class_id].item_size;
	}
	g_slab.slab_base[class_id].free_count += new_count;
	return 0;
}

void slab_init()
{
	g_slab.pool_size = 50*1024*1024;
	g_slab.pool_remain_size = g_slab.pool_size;
	g_slab.pool_base_ptr = (uint8_t *)malloc(g_slab.pool_size);
	g_slab.pool_current_ptr = g_slab.pool_base_ptr;
	g_slab.slab_class_max_count = 100;
	g_slab.factor = 1.25;
	g_slab.smallest_size = 80;
	g_slab.biggest_size = 1024*1024;
	g_slab.class_count = 0;
	g_slab.slab_base = (slab_head *)malloc(g_slab.slab_class_max_count * sizeof(slab_head));
	memset(g_slab.slab_base, 0, g_slab.slab_class_max_count * sizeof(slab_head));
	for(int size = g_slab.smallest_size; size <= g_slab.biggest_size;  ) {
		size *= g_slab.factor;
		if(size % 8) { // 8 is for alignment
			size += 8 - size % 8;
		}
		g_slab.slab_base[g_slab.class_count].item_size = size;
		g_slab.slab_base[g_slab.class_count].total_count = 0;
		g_slab.slab_base[g_slab.class_count].free_count = 0;
		slab_add_page(g_slab.class_count);
		g_slab.class_count++;
		//printf("In %s, g_slab.class_count = %d\n", __FUNCTION__, g_slab.class_count);
	}
}
int slab_find_class(int size){
	for(int i = 0; i < g_slab.class_count; ++i){
		if(g_slab.slab_base[i].item_size >= size) 
			return i;
	}
	return -1;
}
void* slab_alloc(int size)
{
	int id = slab_find_class(size);
	if(g_slab.slab_base[id].free_count <= 0){
		if(slab_add_page(id) == -1) return NULL;
	}
	g_slab.slab_base[id].free_count--;
	item * p = g_slab.slab_base[id].free_list[g_slab.slab_base[id].free_count];
	return p;
}

void slab_free(void *p){
	item * it= (item *)p;
	int id = it->slab_class;
	g_slab.slab_base[id].free_list[g_slab.slab_base[id].free_count] = p;
	g_slab.slab_base[id].free_count++;	
}