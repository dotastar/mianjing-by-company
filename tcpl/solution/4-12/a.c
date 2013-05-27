#include <stdio.h>
#include <math.h>

void itoa(int d, char s[]) {
  static int i = 0;
  if(d/10 != 0)
    itoa(d/10, s);
  if( i == 0 && d < 0 )  {
    s[i++] = '-';
  }

  s[i++] = abs(d) % 10 + '0';
  s[i] = '\0';
  return;
}

int main() {
  char s[128] = {0};
  int i = -1234;
  itoa(i, s);
  printf("%d = %s\n",i, s );
}
