#include <stdio.h>

#define MAXLINE 1000

int getline (char line[], int maxline);
void copy(char to[], char from[]);


main() {
  int len;
  int max;
  char line[MAXLINE];
  char first[MAXLINE];
  char longest[MAXLINE];
  int accum_max;
  
  max = 0;
  accum_max = 0;
  while((len = getline(line, MAXLINE)) > 0) {
    accum_max += len;
    if(len < MAXLINE - 1) {
      if(accum_max > max) {
        max = accum_max;
        if(max >= MAXLINE)
          copy(longest, first);
        else 
          copy(longest, line);
      }
      accum_max = 0;
    } else {
      if(accum_max == MAXLINE - 1)
        copy(first, line);
    }
  }
  if(max > 0)
    printf("%d\n%s\n", max, longest);
  return 0;
}

int getline(char s[], int lim)
{
  int c, i;
  for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
