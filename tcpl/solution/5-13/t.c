#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_NUM 100
#define MAX_LINE_LEN 1000
#define DEFAULT_TAIL_SIZE 10

int getline(char line[], int lim) {
  int c;
  int pos = 0;
  while((c = getchar()) != '\n' && pos < MAX_LINE_LEN) {
    if(c == EOF) return c;
    line[pos++] = c;
  }
  line[pos] = '\0';
  //printf("line is %s\n", line);
  return c;
}

int main(int argc, char *argv[]) {
  char *lines[MAX_LINE_NUM] = {0};
  int begin = 0;//?
  int end = 0;
  int tail_size = DEFAULT_TAIL_SIZE;
  if(argc > 2) {
    printf("usage: a size\n");
    return -1;
  } else {
    tail_size = atoi(argv[1]);
  }
  if(tail_size <= 0)
    tail_size = DEFAULT_TAIL_SIZE;
  if(tail_size > MAX_LINE_LEN)
    tail_size = MAX_LINE_LEN;

  char line[MAX_LINE_LEN] = {0};
  int real_tail_size = 0;
  while(getline(line, MAX_LINE_LEN) != EOF){
    int len = strlen(line);
    //printf("len = %d\n", len);
    char *p = (char *)malloc(len+1);
    strcpy(p, line);
    lines[end] = p;
    end = (end + 1) % MAX_LINE_NUM;
    if(end - begin > tail_size || ((end < begin) && (end + MAX_LINE_NUM - begin > tail_size))) {
      if(lines[begin])
        free(lines[begin]);
      begin = (begin + 1) % MAX_LINE_NUM; 
    }
    if(real_tail_size < tail_size)
      real_tail_size = end - begin;
  }
  printf("begin = %d, end = %d\n", begin, end);
  int i;
  for(i = 0; i < real_tail_size; ++i) {
    int j = (begin + i) % MAX_LINE_NUM;
    printf("%s\n", lines[j]);
  }
}
