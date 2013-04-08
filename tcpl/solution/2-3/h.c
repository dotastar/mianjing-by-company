#include <stdio.h>

int dtoi(char c) {
  if(c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else if (c >= 'A' && c <= 'F') {
      return c - 'A' + 10;
  } else {
    printf("illegal digits\n");
    return 0;
  }
}

int htoi(char s[])
{
  int i = 0;
  if(s[i] != '\0' && s[i+1] != '\0') {
    if(s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
      i += 2;
    }
  }

  int r = 0;
  while(s[i] != '\0') {
    r = r * 16 + dtoi(s[i]);
    ++i;
  }
  return r;
}

int main() {
  char s[] = "0x1fB";
  printf("%d\n", htoi(s));
  
  return 0;
}
