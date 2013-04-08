#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned mask = ~(~0 << p-n+1) | (~0 << p+1);
  x &= mask;
  y = (~( ~0 << n) & y) << (p-n+1);
  return x | y;
}

int main() {
  printf("%d = 11\n", setbits(15, 2, 2, 5));
  return 0;
}
