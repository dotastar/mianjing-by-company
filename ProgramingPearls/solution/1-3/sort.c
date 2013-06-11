#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 10000000
#define LEN 7
int phone_array[NUM];

int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main() {
  //read data
  char phone[LEN+2];
  int i = 0;
  clock_t t = clock();
  for(; i < NUM; ++i) {
    if(fgets(phone, LEN+2, stdin) != NULL) {
      phone[LEN] = '\0';
      phone_array[i] = atoi(phone);
    } else break;
  }
  int n = i;
  //sort data
  qsort(phone_array,n, sizeof(int), compare);
  //print data
  for(i = 0; i < n; ++i) {
    printf("%d\n", phone_array[i]);
  }
  fprintf(stderr, "time %d\n", clock() - t);
  return 0;
}
