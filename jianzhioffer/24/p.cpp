#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool valid(int a[], int low, int high){
  if(low >= high) return true;
  int i = low;
  for(; i <= high - 1; ++i) {
    if(a[i] > a[high])break;
  }
  for(int j = i; j <= high -1; ++j) {
    if(a[j] < a[high]) return false;
  }
  return valid(a, low, i-1) && valid(a, i, high - 1);
}

int main() {
  int a1[]={5,7,6,9,11,10,8};
  cout<<valid(a1, 0, 6)<<endl;
  int a2[]={7,4,6,5};
  cout<<valid(a2, 0, 3)<<endl;

  return 0;
}
