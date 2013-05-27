#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum{NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int getch(void);
void ungetch(int);

int gettoken(void);
void parmdcl(void);
void errmsg(char*);
int compare(char **s, char **t);
int typespec(void);
int typequal(void);
void dclspec(void);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int buf[BUFSIZE];
int bp;

int prevtoken;

int main() {
  while(gettoken() != EOF) {
    strcpy(datatype, token);
    out[0] = '\0';
    dcl();
    //if(tokentype != '\n')
    //  printf("syntax error!\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}


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

void errmsg(char *msg) {
  printf("%s\n", msg);
  prevtoken = 1;
}

int gettoken(void) {
  if(prevtoken){
    prevtoken = 0;
    return tokentype;
  }
  int c, getch(void);
  void ungetch(int);
  char *p = token;
  while((c = getch()) == ' ' || c == '\t');

  if(c == '(') {
    if((c = getch()) == ')'){
      strcpy(token,"()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for(*p++ = c;(*p++ = getch()) != ']';);
    *p = '\0';
    return tokentype = BRACKETS;
  } else if(isalpha(c)) {
    for(*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
}
         
void dcl(void) {
  int ns;
  for(ns = 0; gettoken() == '*';)
    ns++;
  dirdcl();
  while(ns-- > 0)
    strcat(out, " pointer to");
}

void dirdcl(void) {
  int type;

  if(tokentype == '(') {
    dcl();
    if(tokentype != ')')
      errmsg("error: missing )\n");
  } else if(tokentype == NAME)
    strcpy(name, token);
  else
    prevtoken = 1;
    //printf("error: expected name or (dcl)\n");
  while((type = gettoken()) == PARENS || type == BRACKETS || type == '(')
    if(type == PARENS)
      strcat(out, " function returning");
    else if(type == '(') {
      strcat(out, " function expecting");
      parmdcl();
      strcat(out, " and returning");
    }
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

void parmdcl(void) {
  do{
    dclspec();
  } while(tokentype == ',');
  if(tokentype != ')')
    errmsg("missing ) in  parameter declaration\n");
}

void dclspec(void) {
  char temp[MAXTOKEN];
  temp[0] = '\0';
  gettoken();
  do {
    if(tokentype != NAME) {
      prevtoken = 1;
      dcl();
    } else if(typespec() == 1) {
      strcat(temp, " ");
      strcat(temp, token);
      gettoken();
    } else if (typequal() == 1) {
      strcat(temp, " ");
      strcat(temp, token);
      gettoken();
    } else
      errmsg("unkown type in parameter list\n");
  } while(tokentype != ',' && tokentype != ')');
  strcat(out, temp);
  if(tokentype == ',')
    strcat(out, ",");
}

int typespec(void) {
  static char *types[] = {
    "char",
    "int",
    "void"
  };
  char *pt = token;
  if(bsearch(&pt, types, sizeof(types)/sizeof(char *), sizeof(char *), (int (*)(const void*,const void*))compare) == NULL)
    return 0;
  else
    return 1;
}

int typequal(void) {
  static char *typeq[] = {
    "const",
    "volatile"
  };
  char *pt = token;
  if(bsearch(&pt, typeq, sizeof(typeq)/sizeof(char *), sizeof(char *), (int (*)(const void*,const void*))compare) == NULL)
    return 0;
  else
    return 1;
}

int compare(char **s, char **t) {
  return strcmp(*s, *t);
}
