#include <stdio.h>

void wystrncpy(char *s, char *t, int n) {
  int i;
  for(i = 0; i < n && *t; ++i) {
    *s++ = *t++;
  }
  *s = '\0';
}

void wystrncat(char *s, char *t, int n) {
  //  char* bs = s;
  while(*s) ++s;
  int i;
  for(i = 0; i < n && *t; ++i) {
    *s++ = *t++;
  }
  *s = '\0';

}

int wystrncmp(char *s, char *t, int n) {
  int i;
  for(i = 0; i < n && *t; ++i) {
    if(*s++ != *t++) break;
  }

  if((*s == *t && *t == 0) || (i = n))
    return 0;
  else
    return *s - *t;
  
}

int main() {
  char s1[100] = {0};
  wystrncpy(s1, "this is a test", 10);
  printf("strncpy=%s\n", s1);
  char s2[100] = "this is a ";
  wystrncat(s2, "test", 10);
  printf("strncat=%s\n", s2);
  char s3[100] = "this is a test";
  char t3[100] = "this is a dog";  
  
  printf("strncmp=%d\n", wystrncmp(s3, t3, 10));
}
