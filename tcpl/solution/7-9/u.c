#include <stdio.h>

int wyisupper(char c) {
  if(c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}

int main() {
  printf("C is %d\n", wyisupper('C'));
  printf("c is %d\n", wyisupper('c'));
}
