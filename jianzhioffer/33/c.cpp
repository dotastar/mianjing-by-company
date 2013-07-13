#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>


using namespace std;

bool mycmp(string a, string b){
  return a+b < b+a;
}
string print(vector<string> a){
  sort(a.begin(), a.end(), mycmp);
  string result;
  for(auto& i : a){
    result += i;
  }
  return result;
}

int main() {
  vector<string> a = {"3", "32", "321"};
  cout<<print(a)<<endl;
  return 0;
}
