//BKDRHash is from Brian Kernighan and Dennis Ritchie "The C Programming Language"
#include <stdint.h>

uint32_t hash(const uint8_t *key, uint32_t length){
	uint32_t hash = 0;
	for(uint32_t i = 0 ; i < length; ++i){
		hash = hash * 131 + *(key+i);
	}
	return hash;
}