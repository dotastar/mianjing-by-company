#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;

void merge(vector<int>& A, int p, int q, int r){
  int n1= q-p+1;
  int n2 =r-q;
  vector<int> L(n1+1);
  vector<int> R(n2+1);
  for(int i = 0; i < n1; ++i){
    L[i] = A[p+i];
  }
  for(int j = 0; j < n2; ++j){
    R[j] = A[q+1+j];
  }
  L[n1] = numeric_limits<int>::max();
  R[n2] = numeric_limits<int>::max();

  int i = 0;
  int j = 0;
  for(int k = p; k <=r; ++k){
    if(L[i] <= R[j]){
      A[k] =L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void merge_sort(vector<int>& A, int p, int r){
  if(p < r){
    int q = (p+r)/2;
    merge_sort(A, p, q);
    merge_sort(A, q+1, r);
    merge(A, p, q, r);
  }
}

int main() {
  vector<int> A = {2, 4, 5, 7, 1, 2, 3, 6};
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;
  merge_sort(A, 0, A.size()-1);
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
}
