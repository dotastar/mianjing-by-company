#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int print_pattern(FILE *fp, char *filename, char * pattern, int except, int number) {
  char line[MAXLINE];
  long lineno = 0;

  while(fgets(line, MAXLINE, fp) != NULL) {
      lineno++;
      if((strstr(line, pattern) != NULL) != except) {
        if(number)
          printf("%s:%d:", filename, lineno);
        printf("%s", line);
      }
    }
  
}
int main(int argc, char *argv[]) {
  int c, except = 0, number = 0, found = 0;
  char* pattern;
  while(--argc > 0 && (*++argv)[0] == '-')
    while(c = *++argv[0])
      switch(c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        default:
          printf("find: illegal option %c\n",c);
          argc = 0;
          found = -1;
          break;
      }
  if(argc <= 0 )
    printf("Usage: find -x -n pattern\n");
  else {
    pattern = *argv++;
    argc--;
    if(argc == 0) {
      print_pattern(stdin, "stdin", pattern, except, number);
    } else {
      while(--argc >= 0 ){
        char *filename = *argv;
        argv++;
        FILE *fp = fopen(filename, "r");
        print_pattern(fp, filename, pattern, except, number);
      }
    }
  }
  return 0;
}
