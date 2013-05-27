#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char * lineptr[], int nlines);
void writelines(char * lineptr[], int nlines);
void wyqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char*, char*);
int getline(char*, int);
char *alloc(int);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;


int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;
  int reverse = 0;

  while(argc-- > 1) {
    ++argv;
    if( strcmp(*argv, "-n") == 0)
      numeric = 1;
    if( strcmp(*argv, "-r") == 0)
      reverse = 1;
  }
  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    //wyqsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp), reverse);
    if(numeric) wyqsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))numcmp, reverse);
    else wyqsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))strcmp, reverse);
    writelines(lineptr, nlines);
    return 0;
  }else {
    printf("error: input too big to sort\n");
    return 1;
  }
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

int readlines(char * lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getline(line, MAXLEN)) > 0)
    if(nlines  >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  int i;
  for(i = 0; i < nlines; ++i) {
    printf("%s\n", lineptr[i]);
  }
}

void wyswap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void wyqsort(void *v[], int left, int right, int(*comp)(void *, void *), int reverse) {
  int i, last;
  if(left >= right) return;
  wyswap(v, left, (left + right)/2 );
  last = left;
  for(i = left + 1; i <= right; ++i) {
    if(reverse) {
      if((*comp)(v[i], v[left]) > 0)
        wyswap(v, ++last, i);
    } else {
      if((*comp)(v[i], v[left]) < 0)
        wyswap(v, ++last, i);

    }
  }
  wyswap(v, left, last);
  wyqsort(v, left, last-1, comp, reverse);
  wyqsort(v, last+1, right, comp, reverse);
}

int numcmp(char *s1, char *s2) {
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  //printf("%s, %s\n", s1, s2);
  //printf("%f, %f\n", v1, v2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

char *alloc(int n) {
  if(allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else
    return 0;
}

void afree(char *p) {
  if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
