#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>


using namespace std;

int pow10(int len){
  int r = 1;
  for(int i = 1; i < len; ++i)
    r *= 10;
  return r;

}
int base(int len) {
  //len 2 means 1-99
  if(len == 0) return 0;
  if(len == 1) return 1;
  else {
    return pow10(len) + base(len - 1) * 10;
  }
}

int find1(int n){
  if(n <= 0) return 0;
  char s[10] = {0};
  sprintf(s, "%d", n);
  //cout<<"s="<<s<<endl;
  int len = strlen(s);
  int r = 0;
  int n_1 = atoi(s+1);
  //cout<<"n_1="<<n_1<<endl;
  if(s[0] == '1') {
    r \= 1+ n_1;
  } else {
    r = pow10(len);
    r += (s[0] - '2') * base(len-1); 
  }
  for( int i = 1; i < len; ++i) {
    r += base(i);
  }
  return r + find1(n_1);
}

int main() {
  cout<<find1(12)<<endl;
  //cout<<pow10(5)<<endl;
  //cout<<base(4)<<endl;
  return 0;
}
