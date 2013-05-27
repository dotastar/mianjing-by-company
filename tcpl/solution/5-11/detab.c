#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 100
#define TAB_SIZE 8

int main(int argc, char *argv[]) {
  int c, i, j;
  int pos = 0;
  int ns = 0;
  int tab_pos_size;
  int tab_pos[MAX_LINE] = {0};


  if(argc <= 1) {
    for(i = 1, j = 0; i * TAB_SIZE < MAX_LINE; ++i, ++j) {
      tab_pos[i * TAB_SIZE] = 1;
    }
    tab_pos_size = j;
  } else {
    for(j = 1; j < argc; ++j) {
      tab_pos[atoi(argv[j])] = 1;
    }
    tab_pos_size = j - 1;
  }

  for(i = 0; i < 5; ++i) {
    for(j = 0; j < 10; ++j) {
      printf("%d", j);
    }
  }
  printf("\n");

  printf("debug:print tab_pos\n");
  for(i = 0; i < 50; ++i) {
    if(tab_pos[i])
      printf("|");
    else printf(" ");
  }
  printf("\n");

  

  i = 0;
  while((c = getchar()) != EOF) {
    if( c == '\t') {
      while(!tab_pos[pos]) {
        putchar(' ');
        ++pos;
      }
    } else if(c == '\n') {
      pos = 0;
      putchar(c);
    } else {
      ++pos;
      putchar(c);
    }
  }
  return 0;
}
