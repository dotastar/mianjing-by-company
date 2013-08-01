#include <stdio.h>

int zero_count(int n){
  int sum = 0;
  while(n != 0) {
    n /= 5;
    sum += n;
  }
  return sum;
}
int one_pos(int n){
  int sum = 0;
  while(n != 0){
    n >>= 1;
    sum += n;
  }
  return sum+1;
}

int is_pow_2(int n){
  return n>0 && !(n&(n-1));
}

int main() {
  printf("factorial 10 has %d zero in tail, should be 2\n", zero_count(10));
  printf("factorial 10's last 1's pos is %d, should be 9\n", one_pos(10));
  printf("8(is pow of 2) is %d, should be 1\n", is_pow_2(1));
}
