#include <stdio.h>

#define IN 1
#define OUT 0
main() {
  int c;
  int state = OUT;
  while((c = getchar()) != EOF) {
    if(c != ' ' && c != '\t' && c != '\n') {
      putchar(c);
      state = IN;
    } else if(state == IN) {
        putchar('\n');
        state = OUT;
    }
  }
}
