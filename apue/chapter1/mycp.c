#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 4096

int main(int argc, char* argv[]){
  char buf[BUFSIZE] = {0};
  int n;
  while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0){
    if(write(STDOUT_FILENO, buf, n) != n){
      printf("write error\n");
    }
  }
  if(n < 0){
    printf("read error\n");
    exit(1);
  }
  exit(0);
}
