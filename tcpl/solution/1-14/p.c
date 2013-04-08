#include <stdio.h>
#define SIZE 26

main() {
  int c;
  int sum[SIZE] = {0};
  while((c = getchar()) != EOF) {
    if(c >= 'a' && c <= 'z')
      ++sum[c - 'a'];
  }

  int i, j;
  for(i = 0; i < SIZE; ++i) {
    printf("%c:", i + 'a');
    for(j = 0; j < sum[i]; ++j) {
      putchar('*');
    }
    printf("\n");
  }
}
