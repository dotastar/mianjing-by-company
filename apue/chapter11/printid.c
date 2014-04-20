#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void print_tid(char *s){
  pid_t pid = getpid();
  pthread_t tid = pthread_self();
  printf("%s, pid=%u, tid=%u(0x%x)\n", s, pid, (unsigned int)tid, (unsigned int)tid);
}

void* myfunc(void* arg){
  print_tid("mufunc");
  return NULL;
}
int main(){
  pthread_t tid;
  int rc = pthread_create(&tid, NULL, myfunc, NULL);
  if( rc != 0){
    printf("pthread create error!\n");
    return -1;
  }
  print_tid("main");
  sleep(1);
}
