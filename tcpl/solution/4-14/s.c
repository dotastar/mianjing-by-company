#include <stdio.h>

#define swap(t, x, y) \
  {t z = x;\
   x = y;\
   y = z;\
  }

int main() {
  int x = 3;
  int y = 4;
  swap(int, x, y)
  printf("x=%d, y= %d\n", x, y);
}
