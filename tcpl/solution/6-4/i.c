#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode {
  char *word;
  int num;
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100
#define MAXNUM 1000
struct tnode *word_array[MAXNUM];
int array_index = 0;
struct tnode *addtree(struct tnode *, char *);
void tree2array(struct tnode *);
void sort_array();
void print_array();
int getword(char *, int);
struct tnode *talloc(void);
char *wystrdup(char *);

int main(int argc, char *argv[]) {
  struct tnode *root = NULL;
  char word[MAXWORD];
  while(getword(word, MAXWORD) != EOF) {
    //printf("%s\n", word);
    if(isalpha(word[0]))
      root = addtree(root, word);
  }
  tree2array(root);
  sort_array();
  print_array();
  return 0;
}

struct tnode *addtree(struct tnode *p, char *w) {
  int cond;
  if(p == NULL) {
    p = talloc();
    p->word = wystrdup(w);
    p->num = 1;
    p->left = p->right = NULL;
  } else if((cond = strcmp(w, p->word)) == 0) {
    p->num++;
  } else if(cond < 0)
    p->left = addtree(p->left, w);
  else if(cond > 0)
    p->right = addtree(p->right, w);
  return p;
}

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}

void tree2array(struct tnode *p) {
  if(p != NULL) {
    tree2array(p->left);
    if(array_index < MAXNUM)
      word_array[array_index++] = p;
    tree2array(p->right);
  }
}

int qsort_partition(int low, int high){
  struct tnode * p = word_array[low];
  int i = low;
  int j = low+1;
  for(;j <= high; ++j) {
    if(word_array[j]->num > p->num){
      ++i;
      struct tnode *t = word_array[j];
      word_array[j] = word_array[i];
      word_array[i] = t;
    }
  }
  word_array[low] = word_array[i];;
  word_array[i] = p;
  return i;
}

void qsort_array(int low, int high) {
  if(low >= high) return;
  int q = qsort_partition(low, high);
  qsort_array(low, q-1);
  qsort_array(q+1, high);
}

void sort_array() {
  qsort_array(0, array_index-1);
}

void print_array() {
  int i = 0;
  for(; i < array_index; ++i) {
    printf("%d:%s\n", word_array[i]->num, word_array[i]->word);
  }
}

int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()) && c != '\n');
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
