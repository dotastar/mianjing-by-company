#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
  return x ^ (~(~0 << n) << p - n + 1);
}

int main() {
  
  printf("%d = 38\n", invert(42, 3, 2));
  return 0;
}
