#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXOP 100
#define MAXVAL 100
#define NUMBER '0'
#define BUFSIZE 100

int getch(void);
void ungetch(int);
void ungets(char []);
int getop(char[]);
void push(double f);
double pop(void);

int buf[BUFSIZE];
int bufp = 0;
double val[MAXVAL];
int sp = 0;

main() {
  int c;
  ungetch(EOF);
  while((c = getch()) != EOF)
    putchar(c);

  
  /*
  int type, var = 0;
  double op2;
  char s[MAXOP];
  double variable[26] = {0};
  double v = 0;
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
        v = pop();
        printf("\t%.8g\n", v);
        break;
      case '=':
        pop();
        if(var >= 'A' && var <= 'Z')
          variable[var - 'A'] = pop();
        else
          printf("invalid var name!\n");
        break;
      default:
        if(type >= 'A' && type <= 'Z') {
          push(variable[type - 'A']);
        } else if (type == 'v') {
          push(v);
        } else 
          printf("unknown command [%s]\n", s);
        break;
    }
    var = type;
  }
  */
  return 0;
}

int getch(void) {
  return (bufp > 0)?buf[--bufp]:getchar();
}

void ungetch(int c) {
  if(bufp >= BUFSIZE) {
    printf("buf is full\n");
  } else buf[bufp++] = c;
}

void ungets(char s[]) {
  int i;
  for(i = strlen(s) - 1; i >= 0; --i) {
    ungetch(s[i]);
  }
}

int getop(char s[]) {
  int i, c;
  while((s[0] = c = getch()) == ' ' || c == '\t');
  s[1] = '\0';
  if(c == EOF) return c;
  c = getch();
  i = 0;
  if(s[0] == '-' && (isdigit(c) || c == '.')){
    s[++i] = c;
  } else{
    ungetch(c);
    c = s[0];
    if (!isdigit(c) && c != '.') {
        return c;
    }
  }

  //printf("getop get number  [%s]\n", s);
  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()));
  if(c == '.')
    while(isdigit(s[++i] = c = getch()));
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
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

void print_top(void) {
  if(sp > 0)
    printf("%f\n", val[sp-1]);
  else
    printf("empty stack\n");
}

void dup_top(void) {
  if(sp > 0 && sp < MAXVAL) {
    val[sp] = val[sp-1];
    ++sp;
  } else if (sp <= 0)
    printf("empty stack\n");
  else
    printf("stack is full, no room for dup\n");
}

void swap_top(void) {
  if(sp >=2) {
  double t = val[sp-1];
  val[sp-1] = val[sp-2];
  val[sp-2] = t;
  } else
    printf("no enough elemtn for swap\n");
}

void clear(void) {
  sp = 0;
}
