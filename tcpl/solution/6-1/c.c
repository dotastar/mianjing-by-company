#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
  char *word;
  int count;
} keytab[] = {
  {"auto", 0},
  {"break", 0},
  {"case", 0},
  {"char", 0},
  {"else", 0},
  {"for", 0},
  {"if", 0},
  {"int", 0},
  {"return", 0},
  {"while", 0}
};

#define NKEYS (sizeof keytab / sizeof (struct key))
    
    
int getword(char *, int);
int binsearch(char *, struct key *, int);

main() {
  int n;
  char word[MAXWORD];
  while(getword(word, MAXWORD) != EOF) {
    //    printf("%s", word);
  if(isalpha(word[0]))
     if((n = binsearch(word, keytab, NKEYS)) >= 0)
       keytab[n].count++;
  }
  for( n = 0; n < NKEYS; n++)
    if(keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
  return 0;
}

int binsearch(char *word, struct key tab[], int n) {
  int cond;
  int low, high, mid;

  low = 0;
  high = n-1;
  while(low <= high) {
    mid = (low + high) / 2;
    if((cond = strcmp(word, tab[mid].word)) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
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

