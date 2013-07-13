#include <iostream>

using namespace std;

int fib(int n) {
  int f_n = 0;
  if(n < 0) return -1;
  if(n <= 1) return 1;
  int f_n_1 = 1, f_n_2 = 1;
  for(int i = 2; i <= n; ++i) {
    f_n = f_n_1 + f_n_2;
    f_n_2 = f_n_1;
    f_n_1 = f_n;
  }
  return f_n;
}
int main() {
  for(int i = 0 ; i < 10; ++i)
    cout<<fib(i)<<endl;
  return 0;
}
