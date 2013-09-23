#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int partition(vector<int>& A, int p, int r){
  int i = p;
  for(int j = p+1; j <= r; ++j){
    if(A[j] < A[p]){
      ++i;
      swap(A[i], A[j]);
    }
  }
  swap(A[i], A[p]);
  return i;
}

void quick_sort(vector<int>& A, int p, int r){
  if(p < r){
    int q = partition(A, p, r);
    quick_sort(A, p, q-1);
    quick_sort(A, q+1, r);
  }
}

int main() {
  vector<int> A = {2,8,7,1,3,5,6,4};
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;
  quick_sort(A, 0, A.size()-1);
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
}
