#include <iostream>
#include <vector>

using namespace std;

void find_sum1(vector<int>& a, int target) {
  int n = a.size();
  int i = 0, j = n-1;
  while(i < j){
    int sum = a[i] + a[j];
    if(sum > target){
      --j;
    } else if (sum < target){
      ++i;
    }else {
      cout<<a[i]<<" "<<a[j]<<endl;
      return;
    }
  }
  cout<<"not found"<<endl;
}

void find_sum2(int n){
  int i = 1, j = 2;
  int sum = i + j;
  while(i < j ) {
    if(sum < n){
      ++j;
      sum += j;
    } else if(sum > n){
      sum -= i;
      ++i;
    } else {
      cout<<i<<" "<<j<<endl;
      ++j;
      sum += j;      
    }
  }
}

int main() {
  vector<int> a = {1,2,4,7,11,15};
  find_sum1(a, 15);
  cout<<"====="<<endl;
  find_sum2(15);
  return 0;
}

