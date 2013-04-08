#include <stdio.h>

#define MAXLINE 1000

int getline (char line[], int maxline);
void copy(char to[], char from[]);


int main() {
  int len;
  char line[MAXLINE];
  while((len = getline(line, MAXLINE)) > 0) {
    int i;
    for(i = len - 1; i >= 0; --i) {
      if(line[i] != '\n' && line[i] != ' ' && line[i] != '\t')
        break;
    }
    line[i+1] = '\0';
    if(i >= 0) {
      printf("%s",line);
      printf("#end\n");
    }
  }
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
