#include <stdio.h>
#include <limits.h>

int main() {
  printf("signed char range is [%d,%d]\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char range is [%u,%u]\n", 0,UCHAR_MAX);
  printf("signed short range is [%d,%d]\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short range is [%u,%u]\n", 0, USHRT_MAX);
  printf("signed int range is [%d,%d]\n", INT_MIN, INT_MAX);
  printf("unsigned int range is [%u,%u]\n", 0, UINT_MAX);
  printf("signed long range is [%ld,%ld]\n", LONG_MIN, LONG_MAX);
  printf("unsigned long range is [%lu,%lu]\n", 0, ULONG_MAX);
  return 0;
}
