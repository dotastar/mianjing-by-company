#include <stdio.h>

double atof(char s[]) {
  double val = 0;
  int sign = 1;
  int i = 0;

  if(isspace(s[i])) ++i;
  if(s[i] == '-') sign = -1;
  if(s[i] == '-' || s[i] == '+')  ++i;
  while(isdigit(s[i])) {
    val = 10*val + s[i] - '0';
    i++;
  }
  if(s[i] == '.') ++i;

  int power;
  for(power = 1.0; isdigit(s[i]); ++i) {
    val = 10*val + s[i] - '0';
    power *= 10;
  }

  int e_sign = 1;
  if(s[i] == 'e' || s[i] == 'E') ++i;
  if(s[i] == '-') e_sign = 0;
  if(s[i] == '-' || s[i] == '+')  ++i;
  int e;
  for(e = 0; isdigit(s[i]); ++i) {
    e = 10*e + s[i] - '0';
  }

  if(e_sign) {
    while(e > 0) {
      power /= 10;
      --e;
    }
  } else {
    while(e > 0) {
      power *= 10;
      --e;
    }
  }

  return sign*val/power;
}

int main() {
  printf("%e\n", atof("123.45e-6"));
}
