#include <iostream>

using namespace std;

int count1(int n){
  int r = 0;
  while(n != 0){
    n = n & (n-1);
    ++r;
  } 
  return r;
}
int count2(int n){
  int r = 0;
  unsigned int flag = 1;
  while(flag != 0){
    if(n & flag) ++r;
    flag = flag<<1;
  }
  return r;
}

int main() {
  cout<<count1(9)<<endl;
  cout<<count2(9)<<endl;
  return 0;
}
