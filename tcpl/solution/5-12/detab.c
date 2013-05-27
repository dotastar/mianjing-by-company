#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 100
#define TAB_SIZE 8

int tab_start = 0;
int tab_interval = TAB_SIZE;

void process_option(char s[]) {
  if(s[0] == '-') {
    tab_start = atoi(s+1);
  } else if (s[0] == '+') {
    tab_interval = atoi(s+1);
  } else {
    printf("%s is a invalide option\n", s);
  }
}

int main(int argc, char *argv[]) {
  int c, i, j;
  int pos = 0;
  int ns = 0;
  int tab_pos_size;
  int tab_pos[MAX_LINE] = {0};

  if(argc != 3 && argc != 1){
    printf("usage:a -m +n\n");
    return -1;
  }

  if(argc == 3) {
    process_option(argv[1]);
    process_option(argv[2]);
  }

  for(i = 1; i * tab_interval < MAX_LINE; ++i) {
    tab_pos[i*tab_interval + tab_start] = 1;
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
