#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
  int len = 0;
  unsigned t = ~0;
  while(t != 0) {
    t >>= 1;
    ++len;
  }
  n %= len;
  unsigned right = x & ~(~0 << n);
  return (x >> n) | (right << len-n);
}

int main()
{
  printf("%u = 2684354570\n", rightrot(170, 4));
  return 0;
}
