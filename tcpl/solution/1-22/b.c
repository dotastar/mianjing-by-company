#include <stdio.h>

#define N 20
#define TAB_SIZE 8

char line[N];

void printl(int pos)
{
  int i;
  for(i = 0; i < pos; ++i) {
    putchar(line[i]);
  }
  if(pos > 0)
    putchar('\n');
}

int exptab(int pos)
{
  line[pos++] = ' ';
  for(; pos < N && (pos % TAB_SIZE != 0); ++pos)
    line[pos] = ' ';

  if (pos >= N) {
    printl(pos);
    pos = 0;
  }
  return pos;
}
int findblank(int pos)
{
  while(pos > 0 && line[pos] != ' ') --pos;
  if(pos <= 0) return N;
  else return ++pos;
}

int newpos(int pos)
{
  int i, j;
  j = 0;
  for(i = pos; i < N;) {
    line[j++] = line[i++];
  }
  return j;
}

int main()
{
  int c, pos;
  pos = 0;

  printf("01234567890123456789\n");
  
  while((c = getchar()) != EOF) {
    line[pos] = c;
    if(c == '\t') {
      pos = exptab(pos);
    } else if (c == '\n') {
      printl(pos);
      pos = 0;
    } else if (++pos >= N) {
      pos = findblank(pos);
      printl(pos);
      pos = newpos(pos);
    }
  }

  printl(pos);
  
  return 0;
}
