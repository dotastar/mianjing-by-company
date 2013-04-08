#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getop(char[]);
void push(double f);
double pop(void);
int getline (char line[], int maxline);

char buf[BUFSIZE];
int bufp = 0;
double val[MAXVAL];
int sp = 0;

main() {
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF){
    //printf("getop = [%s]\n", s);
    switch(type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if(op2 != 0.0)
          push(fmod(pop(),op2));
        else
          printf("zero mod\n");
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("unknown command [%d]\n", s[0]);
        break;
    }
  }
  return 0;
}

int getch(void) {
  return (bufp > 0)?buf[--bufp]:getchar();
}

void ungetch(int c) {
  if(bufp >= BUFSIZE) {
    printf("buf is full1\n");
  } else buf[bufp++] = c;
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

char line[BUFSIZE]={0};
int lp = 0;
int getop(char s[]) {
  int i, c;
  if(line[lp] == '\0') {
    if(getline(line, BUFSIZE) == 0)
      return EOF;
    else 
      lp = 0;
  }
  while((s[0] = c = line[lp++]) == ' ' || c == '\t');
  s[1] = '\0';
  if (!isdigit(c) && c != '.') {
    return c;
  }
  i = 0;
  //printf("getop get number  [%s]\n", s);
  if(isdigit(c))
    while(isdigit(s[++i] = c = line[lp++]));
  if(c == '.')
    while(isdigit(s[++i] = c = line[lp++]));
  s[i] = '\0';
  if(c != EOF)
    --lp;
  return NUMBER;
}

void push(double f) {
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("stack is full, can't push %f\n", f);
}

double pop(void) {
  if(sp > 0)
    return val[--sp];
  else
    printf("empty stack!\n");
  return 0.0;
}


