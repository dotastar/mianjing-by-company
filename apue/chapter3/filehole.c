#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void){
  int fd = open("file.hole", O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
  if (fd < 0){
    printf("open error\n");
    exit(-1);
  }
  if(write(fd, buf1, 10) != 10){
    printf("write 1 error\n");
    exit(-1);
  }
  if(lseek(fd, 16384, SEEK_SET) == -1) {
    printf("lseek error\n");
    exit(-1);
  }
  if(write(fd, buf2, 10) != 10){
    printf("write 2 error\n");
    exit(-1);
  }
}
