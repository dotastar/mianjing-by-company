#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct lnode {
  int line_num;
  struct lnode *next;
};

struct tnode {
  char *word;
  struct lnode *line_num_list;
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100


struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
int noiseword(char *);
struct tnode *talloc(void);
struct lnode *lalloc(int);
char *wystrdup(char *);

int main(int argc, char *argv[]) {
  struct tnode *root = NULL;
  int line_num = 1;
  char word[MAXWORD];
  while(getword(word, MAXWORD) != EOF) {
    //printf("%s\n", word);
    if(isalpha(word[0]) && noiseword(word) == -1)
      root = addtree(root, word, line_num);
    else if(word[0] == '\n')
      line_num++;
  }
  treeprint(root);
  return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int line_num) {
  int cond;
  if(p == NULL) {
    p = talloc();
    p->word = wystrdup(w);
    p->line_num_list = lalloc(line_num);
    p->left = p->right = NULL;
  } else if((cond = strcmp(w, p->word)) == 0) {
    struct lnode *lp = p->line_num_list;
    while(lp->next) {
      lp = lp->next;
    }
    if(lp->line_num != line_num)
      lp->next = lalloc(line_num);
  } else if(cond < 0)
    p->left = addtree(p->left, w, line_num);
  else if(cond > 0)
    p->right = addtree(p->right, w, line_num);
  return p;
}

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}

struct lnode *lalloc(int line_num) {
  struct lnode* p = (struct lnode *) malloc(sizeof(struct lnode));
  p->line_num = line_num;
  p->next = NULL;
  return p;
}

void treeprint(struct tnode *p) {
  if(p != NULL) {
    treeprint(p->left);
    printf("%10s: ", p->word);
    struct lnode *t;
    for(t = p->line_num_list; t != NULL; t = t->next) {
      printf("%4d ",t->line_num );
    }
    printf("\n");
    
    treeprint(p->right);
  }
}

int noiseword(char *w) {
  static char *nw[] = {"a", "an", "and", "are", "is", "the", "to"};
  int cond, mid;
  int low = 0;
  int high = sizeof(nw)/sizeof(char*) - 1;
  while(low <= high){
    mid = (low + high)/2;
    cond = strcmp(w, nw[mid]);
    if(cond == 0) return mid;
    else if(cond < 0) high = mid - 1;
    else low = mid + 1;
  }
  return -1;
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
