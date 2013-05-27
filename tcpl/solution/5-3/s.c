#include <stdio.h>

void wystrcat(char *s, char *t) {
  while(*s++);
  --s;
  while(*s++ = *t++);
}

int main() {
  char s[100] = "this is ";
  char t[] = "test";
  wystrcat(s, t);
  printf("%s\n", s);
}
