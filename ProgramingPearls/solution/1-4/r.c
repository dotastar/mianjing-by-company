#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sample(int n, int k) {
  int i;
  int *a = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    a[i] = i;
  }
  for(i = 0; i < k; i++){
    //swap i with (i n)
    int r = rand()%(k-i)+i;
    int t = a[r];
    a[r] = a[i];
    a[i] = t;
    fprintf(stdout, "%d\n", a[i]);
  }

  free(a);
}

int main() {
  srand(time(NULL));
  sample(10000000, 1000000);
}
