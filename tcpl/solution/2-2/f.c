#include <stdio.h>

int main() {
  for(i = 0; i < lim - 1; ++i) {
    if((c = getchar()) != '\n') {
      if(c != EOF) {
        s[i] = c;
      } else break;
    } else break;
  }
  return 0;
}
