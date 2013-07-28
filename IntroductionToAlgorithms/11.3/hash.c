#include <stdio.h>
#include <stdint.h>

const uint64_t s = 2654435769; 
const uint32_t p = 14;
const uint32_t w = 32;

uint32_t multiplication_method(uint32_t k){
  uint64_t r = s * k;
  printf("r1+r0 = %llu\n", r);
  printf("r1 = %llu\n", (r >> w) & 0xFFFFFFFF);
  printf("r0 = %llu\n", r & 0xFFFFFFFF);
  return (r & 0xFFFFFFFF) >> (w-p);

}

int main() {
  uint32_t k = 123456;
  printf("multiplication_method(%u) = %u\n",k, multiplication_method(k));
}
