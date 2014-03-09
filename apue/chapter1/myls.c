#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char* argv[]){
  if(argc != 2){
    printf("usage: ls dirname\n");
    exit(1);
  }
  DIR* dp= opendir(argv[1]);
  if(dp == NULL){
    printf("can not open %s\n", argv[1]);
    exit(1);
  }
  struct dirent * de;
  while((de = readdir(dp)) != NULL){
    printf("%s\n", de->d_name);
  }
  closedir(dp);
  exit(0);
}
