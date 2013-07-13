#include <iostream>
#include <string>

using namespace std;

bool next(string& str, int n){
  int len = str.size();
  int i = len-1;
  if(str[i] != '9') {
    str[i]++;
  } else {
    bool carry = true;
    while(carry){
      if(i == 0) {
        if(len == n)
          return false;
        else {
          str = "0" + str;
          ++i;
        }
      }
      str[i] = '0';
      --i;
      if(str[i] != '9'){
        str[i]++;
        carry = false;
      } 
    }
  }
  return true;
}

void printn(int n){
  string str("0");
  while(next(str, n))
    cout<<str<<" ";
  cout<<endl;
}
int main() {
  printn(2);
}
