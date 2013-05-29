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
        printf("unknown command [%s]\n", s);
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

int getop(char s[]) {
  float f;
  int d;
  char c;
  int r;
  do{
    r = scanf("%c", &c);
    if( r == EOF) return EOF;
  } while( c == ' ' || c == '\t');
  s[0] = c;
  s[1] = '\0';
  if(!isdigit(c) && c != '.') return c;
  else ungetc(c, stdin);
  if( scanf("%f", &f) == 1){
    sprintf(s, "%f", f);
    printf("f=[%s]\n",s);
    return NUMBER;
  } else {
    printf("s=[%s]\n",s);
    printf("error\n");
    exit(1);
  }
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


