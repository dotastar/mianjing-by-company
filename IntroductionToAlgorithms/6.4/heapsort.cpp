#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;
void max_heapify(vector<int>& A, int i, const int heap_size){
  int l = 2*i + 1;
  int r = 2*i + 2;
  int largest = i;
  if(l < heap_size && A[l] > A[largest]){
    largest = l;
  }
  if(r < heap_size && A[r] > A[largest]){
    largest = r;
  }
  if(i != largest){
    swap(A[i], A[largest]);
    max_heapify(A, largest, heap_size);
  }
}

void build_max_heap(vector<int>& A, int& heap_size){
    heap_size = A.size();
    for(int i = heap_size/2 - 1; i >= 0; --i){
      max_heapify(A, i, heap_size);
    }
}

void heap_sort(vector<int>& A){
  int heap_size = 0;
  build_max_heap(A, heap_size);
  for(int i = A.size() - 1;i >= 1; --i){
    swap(A[0], A[i]);
    --heap_size;
    max_heapify(A, 0, heap_size);
  }
}

int main() {
  vector<int> A = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
  cout<<endl;
  heap_sort(A);
  copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
}
