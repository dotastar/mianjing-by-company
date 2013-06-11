#include <iostream>
#include <cstring>

using namespace std;

void rev1(char *s){
  size_t len = strlen(s);
  if(len <= 2) return;
  for(size_t i = 0; i < len-i-1; ++i){
    char t = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = t;
  }
}
int main() {
  char s[] = "abcdefg";
  rev1(s);
  cout<<s<<endl;
}
