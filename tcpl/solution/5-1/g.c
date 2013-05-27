#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getint(int *pn) {
  int c , d, sign;
  while(isspace(c = getch()));

  if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-')? -1 : 1;
  if(c == '-' || c == '+') {
    d = c;
    c = getch();
    if(!isdigit(c)) {
        if(c != EOF) {
          ungetch(c);
        }
        ungetch(d);
        return 0;
    }
  }
  
  for(*pn = 0; isdigit(c); c = getch()) {
    *pn = 10 * *pn + c - '0';
  }

  *pn *= sign;
  if(c != EOF) {
    ungetch(c);
  }
  return c;
}

#define BUFSIZE 100
int buf[BUFSIZE];
int bp;

int getch(void) {
  return (bp > 0) ? buf[--bp] : getchar();
}

void ungetch(int c) {
  if (bp >= BUFSIZE) {
    printf("buf is full!");
  } else {
    buf[bp++] = c;
  }
}

int main() {
  int x = 0;
  if(getint(&x)){
    printf("%d\n", x);
  }
  if(getint(&x)) {
    printf("%d\n", x);
  }
  
  return 0;
}
