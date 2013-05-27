#include <stdio.h>
#include <string.h>

void reverser(char s[], int i, int len) {
  int j = len - 1 - i;
  if( i < j) {
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
    reverser(s, i+1, len);
  }
}

void reverse(char s[]) {
  reverser(s, 0, strlen(s));
}

int main() {
  char s[] = "abcd";
  reverse(s);
  printf("%s\n", s);
}
