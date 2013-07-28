#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "main.h"
#include "slab.h"
#include "item.h"

/*
 * memcached has 4 key point:
 * 1. O(1) for all operation
 * 2. LRU
 * 3. slab
 * 4. consistent hash
 */


void init(){
	init_hashtable();
	slab_init();
}

void basic_test() {
	char key1[]="key1";
    char value1[] = "value1";
	char key2[]="key2";
    char value2[] = "value2";

	char key3[]="key1";
    char value3[] = "value3";

	char get_value[10] = {0};
	char *p_value;
	int value_len = 0;

	if(!item_set(key1, strlen(key1)+1, value1, strlen(value1)+1)){
		printf("[fail]set %s fail\n", key1);
	} else {
		printf("[pass]set %s pass\n", key1);
	}
	if(item_get(key2, strlen(key2)+1, (void **)&p_value, &value_len)){
		memcpy(get_value, p_value, value_len);
		printf("[fail]find %s\n", get_value);
	} else {
		printf("[pass]%s not found\n", key2);
	}

	if(!item_set(key2, strlen(key2)+1, value2, strlen(value2)+1)){
		printf("[fail]set %s fail\n", key2);
	} else {
		printf("[pass]set %s pass\n", key2);
	}

	if(item_get(key1, strlen(key1)+1, (void **)&p_value, &value_len)){
		memcpy(get_value, p_value, value_len);
		printf("[pass]find %s\n", get_value);
	} else {
		printf("[fail]%s not found\n", key1);
	}
	if(item_get(key2, strlen(key2)+1, (void **)&p_value, &value_len)){
		memcpy(get_value, p_value, value_len);
		printf("[pass]find %s\n", get_value);
	} else {
		printf("[fail]%s bot found\n", key2);
	}

	if(!item_set(key3, strlen(key3)+1, value3, strlen(value3)+1)){
		printf("[fail]set %s fail\n", key3);
	} else {
		printf("[pass]set %s pass\n", key3);
	}
	if(item_get(key1, strlen(key1)+1, (void **)&p_value, &value_len)){
		memcpy(get_value, p_value, value_len);
		printf("[pass]find %s\n", get_value);
	} else {
		printf("[fail]%s not found\n", key1);
	}
}

void random_test() {
	for(int i = 0; i < 2000; ++i){
		int key1_len = rand()%100 +1;
		int value1_len = rand()%(1024*1024-80) +80;
		uint8_t *key1 = (uint8_t *)malloc(key1_len);
		uint8_t *value1 = (uint8_t *)malloc(value1_len);
		memset(key1, rand()%10 + '0', key1_len);
		key1[key1_len - 1] = '\0';
		memset(value1, rand()%10 + '0', value1_len);
		item_set(key1, key1_len+1, value1, value1_len);
		
		int key2_len = rand()%100 +1;
		//int value2_len;
		int value2_len = rand()%(1024*1024-80) +80;
		uint8_t *key2 = (uint8_t *)malloc(key2_len);
		//uint8_t *value2;
		uint8_t *value2 = (uint8_t *)malloc(value2_len);
		memset(key2, rand()%10 + '0', key2_len);
		key2[key2_len - 1] = '\0';
		memset(value2, rand()%10 + '0', value2_len);
		item_set(key1, key1_len+1, value2, value2_len);
		item_get(key2, key2_len+1, (void **)&value2, &value2_len);
		//printf("%d\n", i);
	}
	

}

int main(int argc, char **argv)
{	
	init();
	basic_test();
	random_test();
	return 0;
}