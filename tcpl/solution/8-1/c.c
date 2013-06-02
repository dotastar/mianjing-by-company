#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1000

void filecopy(int ifh, int ofh)
{
  int buf[BUFSIZE];
  int n = 0;
  while((n = read(ifh, buf, BUFSIZE)) > 0) write(ofh, buf,n); 
}
int main(int argc, char *argv[])
{
  int fh;
  char *prog = argv[0];
  if(argc == 1)
    filecopy(0, 1);
  else
    while (--argc > 0)
      if ((fh = open(*++argv,O_RDONLY))<0) {
        fprintf(stderr,"error\n");
        return -1;
      }else {
        filecopy(fh, 1);
        close(fh);
      }
  return 0;
}
