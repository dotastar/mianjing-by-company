#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>


using namespace std;

int find_sum(vector<int>& a){
  if(a.size() == 0) return 0;
  int current_sum = a[0];
  int history_sum = a[0];
  for(int i = 1; i < a.size(); ++i) {
    if(current_sum + a[i] < 0) {
      current_sum = a[i];
    } else {
      if(current_sum >=0)
        current_sum += a[i];
      else
        current_sum = a[i];
    }
    history_sum = max(history_sum, current_sum);
  }
  return history_sum;
}

int main() {
  vector<int> a = {1,-2,3,10,-4,7,2,-5};
  cout<<find_sum(a)<<endl;
  return 0;
}
