#include <iostream>
#include <vector>

using namespace std;

int find_min(const vector<int>& a) {
  int begin = 0;
  int end = a.size() - 1;
  if(end < 0) return -1;
  while(begin <= end) {//?=
    int mid = (begin + end)/2;
    if(a[mid] >= a[begin] && a[mid] <= a[end]) return a[begin];
    if(a[mid] >= a[begin]){
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}
int main() {
  //vector<int> a = {3,4,5,1,2};
  vector<int> a;
  a.push_back(3);
  a.push_back(4);
  a.push_back(5);
  a.push_back(1);
  a.push_back(2);
  cout<<find_min(a)<<endl;
}
