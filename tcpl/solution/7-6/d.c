#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000
int main() {
  FILE *fp1 = fopen("test1.txt", "r");
  FILE *fp2 = fopen("test2.txt", "r");

  char line1[MAX_LINE];
  char line2[MAX_LINE];
  while(1) {
    char *r1 = fgets(line1, MAX_LINE, fp1);
    char *r2 = fgets(line2, MAX_LINE, fp2);
    if (r1 == NULL &&  r2 == NULL ){
      printf("the same!\n");
      break;
    } else if(r1 == NULL) {
      printf("f1 end\nf2:\n%s\n", line2);
      break;
    } else if(r2 == NULL) {
      printf("f2 end\nf1:\n%s\n", line1);
      break;
    } else {
      if(strcmp(line1, line2) != 0) {
        printf("f1:\n%s\n", line1);
        printf("f2:\n%s\n", line2);
        break;
      }
    }
  }
  fclose(fp1);
  fclose(fp2);
}
