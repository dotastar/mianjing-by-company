#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
  string phone;
  vector<int> v;
  while(getline(cin, phone)) {
    v.push_back(atoi(phone.c_str()));
  }

  sort(v.begin(), v.end());
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
}
