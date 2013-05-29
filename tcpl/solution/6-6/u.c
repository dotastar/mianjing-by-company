#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist{
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101
#define MAXWORD 100

static struct nlist *hashtab[HASHSIZE];
int getword(char *, int);
char *wystrdup(char *);

unsigned hash(char *s) {
  unsigned hashval;
  for(hashval = 0; *s != '\0'; s++) {
    hashval = *s + 31*hashval;
  }
  return hashval % HASHSIZE;
}

int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()));
  if(c != EOF)
    *w++ = c;
  else {
    return c;
  }
  for(; --lim > 0; w++) {
    if(isspace(*w = getch())) {
      ungetch(*w);
      break;
    }
  }
  *w = '\0';
  return word[0];
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

char *wystrdup(char *s) {
  char *p;
  p = (char *) malloc(strlen(s)+1);
  if(p != NULL)
    strcpy(p, s);
  return p;
}

struct nlist *lookup(char *s) {
  struct nlist *np;
  for(np = hashtab[hash(s)]; np != NULL; np = np->next){
    if (strcmp(s, np->name) == 0)
      return np;
  }
  return NULL;
}

struct nlist*install(char *name, char *defn) {
  struct nlist *np;
  unsigned hashval;
  if((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if(np == NULL || (np->name = wystrdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    free((void *)np->defn);
  }
  if((np->defn = wystrdup(defn)) == NULL)
    return NULL;
  return np;
}

void undef(char* name) {
  struct nlist *np, *prev_p;
  unsigned hashval = hash(name);
  for(np = hashtab[hashval]; np != NULL; np = np->next) {
    if(strcmp(np->name, name) == 0) {
      if(np == hashtab[hashval]) hashtab[hashval] = np->next;
      else prev_p->next = np->next;
      free((void *)np->name);
      free((void *)np->defn);
      free((void *)np);
      break;
    }
    prev_p = np;  
  }
}


int main(int argc, char *argv[]) {
  char word[MAXWORD];
  char name[MAXWORD];
  char defn[MAXWORD];
  while(getword(word, MAXWORD) != EOF) {
    //printf("%s\n", word);
    if(strcmp(word, "#define") == 0){
      if(getword(name, MAXWORD) == EOF) break;
      if(getword(defn, MAXWORD) == EOF) break;
      struct nlist* p = install(name, defn);
      printf("install:%s->%s\n", p->name, p->defn);
    }
  }
  return 0;
}
