#include <iostream>
#include <vector>
#include <string>


using namespace std;

void permutation_string(string& str, size_t index) {
  if(index >=  str.size()) {
    cout<<str<<endl;
  }
  for(size_t i = index; i < str.size(); ++i) {
    swap(str[index], str[i]);
    permutation_string(str, index+1);
    swap(str[index], str[i]);
  }
}
int main() {
  string str = "abc";
  permutation_string(str, 0);
  return 0;
}
