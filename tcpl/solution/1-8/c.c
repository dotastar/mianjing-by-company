#include <stdio.h>

main() {
  int c, ns, nt, nl;
  ns = 0;
  nt = 0;
  nl = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ')
      ++ns;
    else if(c == '\t')
      ++nt;
    else if(c == '\n')
      ++nl;
  }

  printf("space = %d, tab = %d, newline = %d\n", ns, nt , nl);
}
