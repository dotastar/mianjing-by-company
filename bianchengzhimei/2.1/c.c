#include <stdio.h>

int count(unsigned char x){
  int sum = 0;
  while(x != 0){
    x &= x-1;
    ++sum;
  }
  return sum;
}
int count2(unsigned int a, unsigned int b){
  unsigned int diff = a^b;
  int sum = 0;
  while(diff != 0){
    diff &= diff - 1;
    ++sum;
  }
  return sum;
}

int main() {
  printf("7 has %d, should be 3\n", count(7));
  printf("307(100110011) and 277(100010101) diff is %d, should be 3\n", count2(307, 277));
  return 0;
}
