#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

char print(string& s){
  int h[256] = {0};
  for(size_t i = 0; i < s.size();++i){
    h[s[i]]++;
  }
  for(size_t i = 0; i < s.size();++i){
    if(h[s[i]] == 1) return s[i];
  }
  return 0;

}

int main() {
  string str("abaccdeff");
  cout<<print(str)<<endl;
  return 0;
}
