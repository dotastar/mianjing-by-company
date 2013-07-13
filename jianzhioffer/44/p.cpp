#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool is_shunzi(vector<int> a){
  sort(a.begin(), a.end());
  int n = a.size();
  int zero_count = 0;
  for(auto& e:a){
    if (e == 0) ++zero_count;
  }
  int shunzi_begin = 0;
  for(; shunzi_begin < n; ++shunzi_begin){
    if(a[shunzi_begin] != 0) break;
  }
  if(shunzi_begin >= n-1) return true;
  int miss_count = 0;
  int j = shunzi_begin;
  for(int i = a[shunzi_begin]; i <= a[n-1]; ++i){
    if(j+1 < n && a[j] == a[j+1]) return false;
    if(i != a[j]){
      ++miss_count;
    } else {
      ++j;
    }
  }
  return zero_count >= miss_count;
}

int main() {
  vector<int> a = {0, 0, 1, 2, 2};
  cout<<is_shunzi(a)<<endl;;
  return 0;
}

