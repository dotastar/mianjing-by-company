#include <stdio.h>

int main() {
  int c, next;
  int in_quote = 0;
  int in_comment = 0;
  while((c = getchar()) != EOF) {
    if( c == '\n' && !in_comment) {
      in_quote = 0;
      putchar(c);
    } else if (c == '\\' && in_quote) {
      next = getchar();
      putchar(c);
      putchar(next);
    }else if(c == '/' && !in_quote && !in_comment) {
      next = getchar();
      if(next == '*')
        in_comment = 1;
      else {
        putchar(c);
        putchar(next);
      }
    } else if ((c == '*') && !in_quote && in_comment) {
      next = getchar();
      if(next == '/')
        in_comment = 0;
      else {
        putchar(c);
        putchar(next);
      }

    } else if ((c == '"') && !in_quote && !in_comment){
      in_quote = 1;
      putchar(c);
    }
    else if ((c == '"') && in_quote && !in_comment){
      in_quote = 0;
      putchar(c);
    } else {
      if(!in_comment) putchar(c);
    }
  }
  return 0;
}
