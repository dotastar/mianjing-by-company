#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;
int main() {
  set<string> words;
  while(1) {
    string s;
    cin>>s;
    if (s == "quit") break;
    words.insert(s);
  }
  copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
  return 0;
}
