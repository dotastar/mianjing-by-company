#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist{
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
  unsigned hashval;
  for(hashval = 0; *s != '\0'; s++) {
    hashval = *s + 31*hashval;
  }
  return hashval % HASHSIZE;
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


int main() {
  install("test","a");
  if(lookup("test") != NULL) printf("install ok\n");
  else printf("install fail");
  undef("test");
  if(lookup("test") == NULL) printf("undef ok\n");
  else printf("undef fail");
}
