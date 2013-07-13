#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void partition(vector<int>& v) {
  int n = v.size();
  int i = -1;
  int k = n-1;
  
  for(int j = 0; j < n; ++j) {
    if(v[j]%2 == 1){
      ++i;
      swap(v[i], v[j]);
    }
  }
}
int main() {
  vector<int> v;
  for(int i = 1; i < 10; ++i) 
    v.push_back(i);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
  cout<<endl;
  partition(v);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
  cout<<endl;
  return 0;
}
