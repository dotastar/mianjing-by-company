#include <stdio.h>
#include <ctype.h>

#define LINE_LEN 80
#define HEX_LEN 6
int main() {
  int c;
  int pos = 0;
  while((c = getchar()) != EOF) {
    if(!isgraph(c)) {
      if(pos + HEX_LEN >= LINE_LEN) {
        printf("\n");
        pos = 0;
      }
      printf(" 0x%X ",c);
      pos += HEX_LEN;
    } else {
      if(pos + 1 >= LINE_LEN) {
        printf("\n");
        pos = 0;
      }
      putchar(c);
      pos++;
    }
  }
}
