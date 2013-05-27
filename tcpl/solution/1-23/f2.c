#include <stdio.h>

void handle_comment(char c) {
  char d;
  while((d = getchar()) != EOF) {
    if(d == '*') {
      d = getchar();
      if(d == '/')
        break;
    }
  }
}

void handle_quote(char c) {
  char d;
  while((d = getchar()) != EOF) {
    if(d == '\\') {
      putchar(d);
      d = getchar();
      putchar(d);
    } else if (d == c) {
      putchar(c);
      break;
    } else {
      putchar(d);
    }
  }
}

void remove_comment(char c) {
  char d;
  if(c == '"' || c == '\'') {
    putchar(c);
    handle_quote(c);
  } else if( c == '/') {
    d = getchar();
    if(d == '*') {
      handle_comment(d);
    } else {
      putchar(c);
      putchar(d);
    }
  } else {
    putchar(c);
  }
}

int main() {
  int c;
  while((c = getchar()) != EOF) {
    remove_comment(c);
  }
  return 0;
}
