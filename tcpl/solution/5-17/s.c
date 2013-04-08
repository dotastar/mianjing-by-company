#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXLEN 1000
#define ALLOCSIZE 10000
#define NUMERIC (1)
#define REVERSE (1<<1)
#define FOLD (1<<2)
#define DIR (1<<3)

char *lineptr[MAXLINES];

int readlines(char * lineptr[], int nlines);
void writelines(char * lineptr[], int nlines);
void wyqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char*, char*);
int wycmp(char*, char*);
int getline(char*, int);
char *alloc(int);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
static int options = 0;
int pos1 = 0;
int pos2 = 0;

int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;
  int reverse = 0;
  int c;

  while(--argc > 0 && ((c = (*++argv)[0]) == '-') || c == '+') {
  if(c == '-' && !isdigit(*(argv[0]+1))) {
      while(c = *++argv[0]){
        switch(c) {
          case 'n':
            options |= NUMERIC;
            break;
          case 'r':
            options |= REVERSE;
            break;
          case 'f':
            options |= FOLD;
            break;
          case 'd':
            options |= DIR;
            break;
          default:
            printf("unkown option - %c\n", c);
            break;
        }
      }
  } else if (c == '-') {
    pos2 = atoi(argv[0] + 1);
  } else if ((pos1 = atoi(argv[0] + 1)) < 0) {
      printf("pos1 error!\n usage: sort -dfnr [+pos1] [-pos2]\n");
      return -1;
  }
  }

  if(argc || pos1 > pos2) {
    printf("usage: sort -dfnr [+pos1] [-pos2]\n");
    return -1;
  }
  
  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    //writelines(lineptr, nlines);
    //wyqsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp), reverse);
    if(options & NUMERIC) wyqsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))numcmp);
    else  wyqsort((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))wycmp);
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
      return -1;    else {
      line[len-1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  int i;
  if(options & REVERSE) {
    for(i = nlines - 1; i >= 0; --i) {
      printf("%s\n", lineptr[i]);
    }
  } else {
    for(i = 0; i < nlines; ++i) {
      printf("%s\n", lineptr[i]);
    }
  }
}

void wyswap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void sub_str(char *s, char *t){
  int len = strlen(s);
  if(pos2 > 0 && len > pos2)
    len = pos2;
  else if(pos2 > 0 && len < pos2) {
    //printf("string is too short!\n");
    //return;
  }
  int i,j;
  for(i = pos1, j = 0; i < len; ++i, ++j) {
    t[j] = s[i];
  }
  t[j] = '\0';
}

void wyqsort(void *v[], int left, int right, int(*comp)(void *, void *)) {
  int i, last;
  if(left >= right) return;
  wyswap(v, left, (left + right)/2 );
  last = left;
  for(i = left + 1; i <= right; ++i) {
    if((*comp)(v[i], v[left]) < 0)
      wyswap(v, ++last, i);
  }
  wyswap(v, left, last);
  wyqsort(v, left, last-1, comp);
  wyqsort(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2) {
  double v1, v2;
  char str[MAXLEN] = {0};
  sub_str(s1, str);
  v1 = atof(str);
  sub_str(s2, str);
  v2 = atof(str);
  //printf("%s, %s\n", s1, s2);
  //printf("%f, %f\n", v1, v2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int is_valid_dir_char(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ';
}

int to_lower(char c) {
  if(c >= 'A' && c <= 'Z') c  -= 'A' - 'a';
  return c;
}

int wycmp(char *s1, char *s2) {
  //printf("%s, %s\n", s1, s2);
  char c1, c2;
  char str1[MAXLEN] = {0};
  char str2[MAXLEN] = {0};
  sub_str(s1, str1);
  sub_str(s1, str2);

  char *sp1 = str1;
  char *sp2 = str2;
  do {
    if( options & DIR) {
    while(!is_valid_dir_char(*sp1) && *sp1 != '\0') ++sp1;
    while(!is_valid_dir_char(*sp2) && *sp2 != '\0') ++sp2;
    }
      c1 = *sp1;
      c2 = *sp2;
      ++sp1;
      ++sp2;

    if(options & FOLD) {
      c1 = to_lower(c1);
      c2 = to_lower(c2);
    } 
  } while(c1 == c2 && c1 != '\0');
  return c1 - c2;
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
