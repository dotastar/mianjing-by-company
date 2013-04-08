#include <stdio.h>
#include <limits.h>

void itoa( int n, char s[], int w) {
  int i = 0;
  int sign = n;
  do {
    int d = n % 10;
    if(d < 0) d = -d;
    s[i++] = d + '0';
  } while((n /= 10) != 0);

  if(sign < 0) s[i++] = '-';
  while(i < w) s[i++] = ' ';
  s[i] = '\0';

  //printf("%s\n", s);
  int j;
  for(j = 0; j < i/2; ++j) {
    char t = s[j];
    s[j] = s[i-1-j];
    s[i-1-j] = t;
  }
}

int main() {
  char s1[100] = {0};
  int n1 = -56;
  itoa(n1, s1, 5);
  printf("%d is [%s]\n", n1, s1);
  char s2[100] = {0};
  int n2 = INT_MIN;
  itoa(n2, s2, 5);
  printf("%d is [%s]\n",n2, s2);
}
