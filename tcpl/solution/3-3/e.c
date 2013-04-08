#include <stdio.h>

void expand(char s1[], char s2[]) {
  int i, j;
  for(i = 0, j = 0; s1[i] != '\0';) {
    if(s1[i+1] == '-' && s1[i+2] > s1[i]) {
      char k;
      for(k = s1[i]; k < s1[i+2]; ++k) {
        s2[j++] = k;
      }
      i += 2;
    } else {
      s2[j++] = s1[i++];
    }
  }
  s2[j] = '\0';
}

int main() {
  char s11[] = "a-b-c";
  char s12[100] = {0};
  expand(s11, s12);
  printf("%s => %s\n", s11, s12);
  
  char s21[] = "a-z0-9";
  char s22[100] = {0};
  expand(s21, s22);
  printf("%s => %s\n", s21, s22);
  
  char s31[] = "-a-z";
  char s32[100] = {0};
  expand(s31, s32);
  printf("%s => %s\n", s31, s32);
}
