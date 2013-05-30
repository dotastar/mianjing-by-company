#include <stdio.h>

#define PAGE_LINE 5
#define MAX_LINE 50

int main(int argc, char *argv[]) {
  int page_number = 0;
  int line_number = 0;
  while(--argc > 0) {
    FILE* fp = fopen(*++argv,"r");
    page_number++;
    printf("===\nheader:%s\n===\n", *argv);
    line_number = 0;
    char line[MAX_LINE];
    while(fgets(line, MAX_LINE, fp) != NULL){
      line_number++;
      if(line_number > PAGE_LINE) {
        printf("footer:page num:%d\n", page_number);
        printf("===\nheader:%s\n===\n", *argv);
        line_number = 1;
        page_number++;
       }
      printf("%d:%s\n",line_number,line);
    }
    printf("footer:page num:%d\n", page_number);
  }
  return 0;

}
