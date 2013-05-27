#include <stdio.h>

void escape1(char s[], char t[])
{
  int i, j;
  for(i = j = 0; t[i] != '\0'; ++i) {
    switch(t[i]) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      case '\\':
        s[j++] = '\\';
        s[j++] = '\\';
        break;
      default:
        s[j++] = t[i];
        break;
    }
  }
  s[j] = '\0';
}

void escape2(char s[], char t[])
{
  int i, j;
  for(i = j = 0; t[i] != '\0'; ++i) {
    if(t[i] == '\\') {
      switch(t[++i]) {
        case 'n':
          s[j++] = '\n';
          break;
        case 't':
          s[j++] = '\t';
          break;
        case '\\':
          s[j++] = '\\';
          break;
        default:
          s[j++] = '\\';
          s[j++] = t[i];
          break;
      }
    } else s[j++] = t[i];
  }
  s[j] = '\0';
}

int main() {
  char s1[50] = {0};
  char t1[] = "as\tdf\nas\\df";
  escape1(s1, t1);
  printf("escape1:\ns1=%s\nt1=%s\n", s1, t1);
  char s2[50] = {0};
  char t2[]="as\\tdf\\nas\\\\df";
  escape2(s2, t2);
  printf("escape2:\ns2=%s\nt2=%s\n", s2, t2);
  return 0;
}
