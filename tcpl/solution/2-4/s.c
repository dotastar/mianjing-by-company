#include <stdio.h>

void squeeze(char s[], char t[])
{
  int i, j, k;
  for(i = j = 0; s[i] != '\0'; ++i) {
    for(k = 0; t[k] != '\0'; ++k) {
          if(s[i] == t[k]) {
            break;
          }
    }
    if('\0' == t[k]) {
        s[j++] = s[i];
    }
  }
  s[j] = '\0';
}

int main() {
  char s[] = "string is t a r g e t !";
  char t[] = "target ";
  squeeze(s, t);
  printf("%s\n", s);
  return 0;
}
