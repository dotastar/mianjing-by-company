#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int count(vector<int>& a, vector<int>& t, int low, int high){
  if(low >= high) return 0;
  int mid = low + (high - low)/2;
  int left = count(a, t, low, mid);
  int right = count(a, t, mid+1, high);
  int i1 = mid, i2 = high, i3 = high;
  int c = 0;
  while(i1 >=low && i2 >=mid+1) {
    if(a[i1] > a[i2]) {
      t[i3] = a[i1];
      c += i2 - mid;
      --i1;
      --i3;
    } else {
      t[i3] = a[i2];
      --i2;
      --i3;
    }
  }
  if(i1 < low) {
    while(i2 >=mid+1){
      t[i3--] = a[i2--];
    }
  } else {
    while(i1 >=low){
      t[i3--] = a[i1--];
    }
  }
  for(int i =low; i <=high; ++i) {
    a[i] = t[i];
  }
  return left+right+c;
}

int main() {
  vector<int> a = {7,5,6,4};
  vector<int> t = a;
  cout<<count(a, t, 0, a.size() - 1)<<endl;
  return 0;
}
