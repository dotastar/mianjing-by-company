#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_num(vector<int>& a, int target) {
  int n = a.size();
  int begin = 0, end = 0;
  //find begin
  int low = 0, high = n-1;
  while(low <= high){
    int mid = low + (high-low)/2;
    if(target < a[mid] ){
      high = mid-1;
    } else if(target > a[mid]) {
      low = mid+1;
    } else {
      if(a[mid-1] == target) high = mid -1;
      else {
        begin = mid;
        break;
      }
    }
  }
  //find end
  low = 0;
  high = n-1;
  while(low <= high){
    int mid = low + (high-low)/2;
    if(target < a[mid] ){
      high = mid-1;
    } else if(target > a[mid]) {
      low = mid+1;
    } else {
      if(a[mid+1] == target) low = mid + 1;
      else {
        end = mid;
        break;
      }
    }
  }

  return end - begin + 1;
}

int main() {
  vector<int> a = {1,2,3,3,3,3,4,5};
  cout<<find_num(a, 3)<<endl;
  return 0;
}

