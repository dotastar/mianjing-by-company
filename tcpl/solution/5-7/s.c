#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTOR 5000

char *lineptr[MAXLINES];
int readlines(char * lineptr[], char * linestor, int nlines);
void writelines(char * lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

main() {
  int nlines;
  char linestor[MAXSTOR] = {0};
  if((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines-1);
    writelines(lineptr, nlines);
    return 0;
  }else {
    printf("error: input too big to sort\n");
    return 1;
  }
}


int getline(char*, int);
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

/*
int readlines(char * lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLINES];

  nlines = 0;
  while((len = getline(line, MAXLINES)) > 0)
    if(nlines  >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}
*/

int readlines(char * lineptr[], char *linestor, int maxlines) {
  int len, nlines;
  char *p = linestor, line[MAXLINES];

  nlines = 0;
  while((len = getline(line, MAXLINES)) > 0)
    if(nlines  >= maxlines || p + len > linestor + MAXSTOR )
      return -1;
    else {
//printf("%s\n", line);
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;

//printf("%d\n", nlines);

    }
  return nlines;
}
void writelines(char *lineptr[], int nlines) {
  int i;
  for(i = 0; i < nlines; ++i) {
    printf("%s\n", lineptr[i]);
  }
}

void wyswap(char *v[], int i, int j) {
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void qsort(char *v[], int left, int right) {
  int i, last;
  if(left >= right) return;
  wyswap(v, left, (left + right)/2 );
  last = left;
  for(i = left + 1; i <= right; ++i) {
    if(strcmp(v[i], v[left]) < 0)
      wyswap(v, ++last, i);
  }
  wyswap(v, left, last);
  qsort(v, left, last -1);
  qsort(v, last+1, right);
}


