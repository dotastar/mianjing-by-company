#include <iostream>
#include <initializer_list>
#include <algorithm>


using namespace std;

int print(int n){
  if (n < 0) return 0;
  int *a = new int[n];
  a[0] = 1;
  int i2 = 0, i3 = 0, i5 = 0;
  int i = 1;
  while(i < n) {
    int next = min(a[i2]*2, a[i3]*3);
    next = min(next, a[i5]*5);
    while(a[i2]*2<= next) ++i2;
    while(a[i3]*3<= next) ++i3;
    while(a[i5]*5<= next) ++i5;
    a[i++] = next;
  }
  int result = a[n-1];
  delete[] a;
  return result;
}

int main() {
  cout<<print(1500)<<endl;
  return 0;
}
