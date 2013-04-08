#include <stdio.h>

void itob(int n, char s[], int b) {
  int i = 0;
  int sign = n;
  do {
    int d = n % b;
    if(d < 0) d = -d;
    if(d < 10) {
      s[i++] = d + '0';
    } else {
      s[i++] = d - 10 + 'A';
    }
  } while((n /= b) != 0);

  if(sign < 0) s[i++] = '-';
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

  int n1 = 28;
  char s1[100] = {0};
  itob(n1, s1, 8);
  printf("%d is %s\n", n1, s1);

  int n2 = 28;
  char s2[100] = {0};
  itob(n1, s1, 16);
  printf("%d is %s\n", n1, s1);
}
