#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


struct tnode {
  char *word;
  int match;
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100

// for testing
int aaaaaa = 1;
int aaaaaa7 = 1;
int aaaaaa78 = 1;
int aaaaa678 = 1;
int bbbbbb = 1;
int bbbbbb7 = 1;

struct tnode *addtree(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *wystrdup(char *);
int wystrcmp(char *, struct tnode *, int, int *);

int main(int argc, char *argv[]) {
  struct tnode *root = NULL;
  int num = (--argc &&(*++argv)[0] == '-')?atoi(argv[0]+1):6;
  char word[MAXWORD];
  int found = 0;
  while(getword(word, MAXWORD) != EOF) {
    //    printf("%s", word);
    if(isalpha(word[0]) && strlen(word) >= num)
      root = addtree(root, word, num, &found);
      found = 0;
  }
  treeprint(root);
  return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int num, int *found) {
  int cond;
  if(p == NULL) {
    p = talloc();
    p->word = wystrdup(w);
    p->match = *found;
    p->left = p->right = NULL;
  } else if((cond = wystrcmp(w, p, num, found)) < 0) {
    p->left = addtree(p->left, w, num, found);
  } else if(cond > 0)
    p->right = addtree(p->right, w, num, found);
  return p;
}

int wystrcmp(char *s, struct tnode *p, int num, int *found) {
  int i;
  char *t = p->word;
  for(i = 0; *s == *t; i++, s++, t++)
    if(*s == '\0')
      return 0;
  if(i >= num) {
    *found = 1;
    p->match = 1;
  }
  return *s - *t;
}

void treeprint(struct tnode *p) {
  if(p != NULL) {
    treeprint(p->left);
    if(p->match)
      printf("%s\n", p->word);
    treeprint(p->right);
  }
}


/*
int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()));
  if(c != EOF)
    *w++ = c;
  if(!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for(; --lim > 0; w++) {
    if(!isalnum (*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
}
*/

int getword(char *word, int lim) {
  int c, d, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()));  
  if(c != EOF)
    *w++ = c;
  if(isalpha(c) || c == '_' || c == '#') {
    for(; --lim > 0; w++) {
      if(!isalnum (*w = getch()) && *w != '_') {
        ungetch(*w);
        break;
      }
    }
  } else if (c == '\'' || c == '"'){
    while((d = getch()) != EOF){
      if(d == '\\') {
        getch();
        continue;
      }
      if( d == c) break;
      //printf("c=%c, d=%c", c,d);
    }
  }
  else if(c == '/') {
    if( (d = getch()) == '*') {
      //in comment
      while((d = getch()) != EOF){
        if(d == '*') {
          if ((d = getch()) == '/')
            break;
          else ungetch(d);
        }
      }
      
    } else ungetch(d);
  }
  
  *w = '\0';
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

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *wystrdup(char *s) {
  char *p;
  p = (char *) malloc(strlen(s)+1);
  if(p != NULL)
    strcpy(p, s);
  return p;
}
