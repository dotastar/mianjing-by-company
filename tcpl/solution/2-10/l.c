#include <stdio.h>

char lower(char c)
{
  return (c >= 'A' && c <= 'Z')?c - 'A' + 'a':c;
}

int main() {
  printf("%c = c\n", lower('c'));
  printf("%c = c\n", lower('C'));
  return 0;
}
