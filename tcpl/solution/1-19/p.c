#include <stdio.h>

#define MAXLINE 1000

int getline (char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

int main() {
  int len;
  char line[MAXLINE];
  while((len = getline(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s",line);
  }
  return 0;
}

void reverse(char s[])
{
  int len;
  int i;
  for(i = 0;s[i] != '\0'; i++);
  i--;
  if(s[i] == '\n') i--;
  int low, upp;
  low = 0;
  upp = i;
  while(low < upp) {
    char t = s[upp];
    s[upp] = s[low];
    s[low] = t;
    ++low;
    --upp;
  }
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
