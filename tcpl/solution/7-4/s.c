#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void minscanf(char *fmt, ...) {
  va_list ap;
  char *p, *sval;
  int *ival;
  float *dval;

  va_start(ap, fmt);
  for(p = fmt;*p;++p){
    if(isspace(*p)) continue;
    if(*p != '%') {
      continue;
    }
    switch(*++p) {
      case 'd':
        ival = va_arg(ap,int*);
        scanf("%d",ival);
        break;
      case 'f':
        dval = va_arg(ap, float*);
        scanf("%f", dval);
        break;
      case 's':
        sval = va_arg(ap, char *);
        scanf("%s",sval);
        break;
      default:
        break;
    }
  }
  va_end(ap);
}

int main() {
  int i;
  float d;
  char s[100] = {0};
  minscanf("%d %f %s\n", &i, &d, s);

  printf("%d %f %s\n", i, d, s);
}
