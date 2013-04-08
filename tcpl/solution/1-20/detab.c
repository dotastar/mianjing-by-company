#include <stdio.h>

#define TAB_SIZE 8

int main() {
  int c;
  int pos = 0;

  int i, j;
  for(i = 0; i < 5; ++i) {
    for(j = 0; j < 10; ++j) {
      printf("%d", j);
    }
  }
  printf("\n");
  
  while((c = getchar()) != EOF) {
    if(c == '\n') {
      pos = 0;
      putchar(c);
    } else if ( c == '\t') {
      int ns = TAB_SIZE - (pos % TAB_SIZE);
      while(ns > 0) {
        putchar(' ');
        --ns;
        ++pos;
      }
    } else {
      putchar(c);
      ++pos;
    }
  }
  return 0;
}
