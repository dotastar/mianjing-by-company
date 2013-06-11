#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>

using namespace std;

int main(){
  clock_t t = clock();
  string phone;
  vector<int> v;
  while(getline(cin, phone)) {
    v.push_back(atoi(phone.c_str()));
  }

  sort(v.begin(), v.end());
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\n"));
  cerr<<"time:"<<clock() - t<<endl;
}
