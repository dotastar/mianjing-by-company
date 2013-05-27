#include <stdio.h>

#define SIZE 10
main() {
  int c;
  int word_length;
  word_length = 0;
  int sum[SIZE];
  int i, j;
  for(i = 0; i < SIZE; ++i) {
    sum[i] = 0;
  }
  
  while((c = getchar()) != EOF) {
    if(c != ' ' && c != '\t' && c != '\n') {
      ++word_length;
    } else if (word_length != 0) {
      ++sum[word_length];
      word_length = 0;
    }
  }

  for(i = 1; i < SIZE; ++i) {
    printf("[%3d]:", i);
    for(j = 0; j < sum[i]; ++j)
      putchar('*');
    putchar('\n');
  }
}
