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

  int max_length;
  max_length = 0;
  for(i = 1; i < SIZE; ++i) {
    if(max_length < sum[i])
      max_length = sum[i];
  }
  for(i = max_length; i > 0; --i) {
    for(j = 1; j < SIZE; ++j)
      if(sum[j] >= i)
        printf("  *  ");
      else
        printf("     ");
    putchar('\n');
  }
  for(i = 1; i <= (SIZE - 1) * 5; ++i)
    putchar('-');
  putchar('\n');
  for(i = 1; i < SIZE; ++i){
    printf("[%3d]", i);
  }
  putchar('\n');
}
