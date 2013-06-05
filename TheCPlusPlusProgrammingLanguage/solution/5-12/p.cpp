#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int count_string(const string &str, char a, char b) {
  int c = 0;
  for(string::const_iterator i = str.begin(); i+1 != str.end(); ++i) {
    if(*i == a && *(i+1) == b) ++c;
  }
  return c;
}

int count_cstring(const char* str, char a, char b) {
  int c = 0;
  int n = strlen(str);
  for(int i = 0; i < n-1; i++) {
    if(str[i] == a && str[i+1] == b) ++c;
  }
  return c;
}

int main() {

  const string s = "xabaacbaxabb";
  cout<<count_string(s, 'a', 'b')<<endl;
  cout<<count_cstring(s.c_str(), 'a', 'b')<<endl;
  return 0;
}
