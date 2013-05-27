#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 100
int stack[STACK_SIZE];
int sp;
int main(int argc, char *argv[]) {
  int i;
  for(i = 1; i < argc; ++i){
    //printf("argv[i][0]=%c\n", argv[i][0]);
    if(isdigit(argv[i][0])){
      stack[sp++] = atoi(argv[i]);
    } else {
      switch(argv[i][0]) {
        case '+':
          if(sp < 2){
            printf("no enough element!\n");
            return 1;
          }
          stack[sp-2] += stack[sp-1];
          sp--;
          break;
        case '-':
          if(sp < 2){
            printf("no enough element!\n");
            return 1;
          }
          stack[sp-2] -= stack[sp-1];
          sp--;
          break;
        case '*':
          if(sp < 2){
            printf("no enough element!\n");
            return 1;
          }
          stack[sp-2] *= stack[sp-1];
          sp--;
          break;
        case '/':
          if(sp < 2){
            printf("no enough element!\n");
            return 1;
          }
          stack[sp-2] /= stack[sp-1];
          sp--;
          break;
        case '\n':
          if(sp != 1){
            printf("no enough element for print!\n");
            return 1;
          } else {
            printf("%d\n", stack[--sp]);
            return 0;            
          }
          break;
        default:
          printf("invalide op[%d]!\n", argv[i][0]);
            return 1;
      }
    }
  }
  if(sp != 1){
    printf("no enough element for print!\n");
    return 1;
  } else {
    printf("%d\n", stack[--sp]);
    return 0;            
  }
}
