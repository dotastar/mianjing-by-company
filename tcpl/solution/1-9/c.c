#include <stdio.h>

main() {
  int c, p;
  p = 'a';
  while((c = getchar()) != EOF) {
    if(c != ' ' || p != ' ')
      putchar(c);
    p = c;
  }
}
