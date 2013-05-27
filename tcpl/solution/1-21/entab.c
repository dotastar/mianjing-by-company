#include <stdio.h>

#define TAB_SIZE 8

int main() {
  int c;
  int pos = 0;
  int ns = 0;

  int i, j;
  for(i = 0; i < 5; ++i) {
    for(j = 0; j < 10; ++j) {
      printf("%d", j);
    }
  }
  printf("\n");
  
  while((c = getchar()) != EOF) {
    if(((pos % TAB_SIZE) == 0) && ns != 0) {
      printf("\t");
      ns = 0;
    }
    if ( c == ' ') {
        ++ns;
        ++pos;
    } else {
      if( c == '\t') {
        ns = 0;
        pos = (pos/TAB_SIZE + 1) * TAB_SIZE;
      } else {
        while(ns > 0) {
          putchar(' ');
          --ns;
        }
        ++pos;
      }
      putchar(c);
    }
    if(c == '\n') {
      pos = 0;
    }
  }
  return 0;
}
