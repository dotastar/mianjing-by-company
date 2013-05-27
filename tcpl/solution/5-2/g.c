#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

int getfloat(double *pn) {
  int c , d, sign;
  while(isspace(c = getch()));

  if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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
  if(c == '.')
    c = getch();
  int power = 1;
  for(; isdigit(c); c = getch()) {
    *pn = 10 * *pn + c - '0';
    power *= 10;
  }

  *pn *= sign;
  *pn /= power;
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
  double x = 0;
  if(getfloat(&x)){
    printf("%f\n", x);
  }
  
  if(getfloat(&x)) {
    printf("%f\n", x);
  }
  
  return 0;
}
