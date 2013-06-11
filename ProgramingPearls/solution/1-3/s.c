#include <stdio.h>
#include <time.h>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000

int a[1+N/BITSPERWORD];
void set(int i) {a[i>>SHIFT] |= 1 << (i&MASK);}
void clr(int i){a[i>>SHIFT] &= ~(1 << (i&MASK));}
int test(int i){ return a[i>>SHIFT] & 1 << (i&MASK);}
int main() {
  int num = 0;
  int i = 0;
  clock_t t = clock();
  while(fscanf(stdin, "%d", &num) != EOF) {
    set(num);
    ++i;
  }
  int n = i;
  for(i = 0; i < N; ++i) {
    if(test(i))
      fprintf(stdout, "%d\n", i);
  }
  fprintf(stderr, "time:%d\n", clock()-t);
  return 0;
}
