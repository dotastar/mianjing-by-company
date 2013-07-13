#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int my_partition(vector<int>& a, int low, int high){
  int i = low;
  for(int j = low+1; j <= high; ++j) {
    if(a[j] < a[low]){
      ++i;
      swap(a[i], a[j]);
    }
  }
  swap(a[i], a[low]);
  return i;
}
int find_number1(vector<int> a){
  int low = 0, high = a.size();
  int mid = (high+low)/2;

  while(low <= high) {
    int i = my_partition(a, low, high);
    if(i < mid) low = i + 1;
    else if(i > mid) high = i - 1;
    else return a[mid];
  }
  cerr<<"error"<<endl;
  return a[mid];
}

int find_number2(vector<int> a){
  int n = a[0], c = 1;
  for(size_t i = 1; i < a.size(); ++i){
    if(a[i] == n) ++c;
    else --c;
    if(c == 0) {
      n = a[i];
      ++c;
    }
    //cout<<"--"<<a[i]<<","<<n<<","<<c<<endl;
  }
  return n;
}

int main() {
  vector<int> a = {1,2,3,2,2,2,5,4,2};
  cout<<find_number1(a)<<endl;
  cout<<find_number2(a)<<endl;
  return 0;
}
