#include <stdio.h>

int strend(char *s, char *t) {
  char *sp = s, *tp = t;
  while(*sp) sp++;
  int s_len = sp - s;
  while(*tp) tp++;
  int t_len = tp - t;
  if( s_len < t_len) return 0;
  //printf("s=%d, t=%d\n", s_len, t_len);
  int i;
  for(i = 0; i < t_len; ++i) {
    if(*(sp - t_len + i) != *(t + i))
      return 0;
  }
  
  return 1;
}
int main () {
  char s[] = "this is a test";
  char t[] = "dest";
  printf("%d\n", strend(s, t));
}
