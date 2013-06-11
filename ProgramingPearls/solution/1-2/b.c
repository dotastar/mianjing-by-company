#include <stdio.h>
#define NUM 1000000/8
unsigned char array[NUM];
void set1(unsigned char a[], int i){
  int size = sizeof(unsigned char);
  int array_index = i / size;
  int bit_index = i % size;
  //printf("set %d\n", b<<bit_index);
  a[array_index] |= 1<<bit_index;
  //printf("set %d\n",a[array_index]);
}

void set0(unsigned char a[], int i){
  int size = sizeof(unsigned char);
  int array_index = i / size;
  int bit_index = i % size;
  //printf("set %d\n", b<<bit_index);
  a[array_index] &= ~(1<<bit_index);
  //printf("set %d\n",a[array_index]);
}

int get(unsigned char a[], int i) {
  int size = sizeof(unsigned char);
  int array_index = i/size;
  int bit_index = i%size;
  //printf("get %d\n",a[array_index]);
  if((a[array_index] & 1<<bit_index) > 0) return 1;
  else return 0;
}
int main() {
  int i = 39;
  printf("%d\n",get(array, i));
  set1(array, i);
  printf("%d\n",get(array, i));
  set0(array, i);
  printf("%d\n",get(array, i));
  
}
