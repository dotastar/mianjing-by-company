#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>


using namespace std;

void findk(vector<int>& a, int k, multiset<int, greater<int>>& selected){
  for(auto& i : a) {
    if(selected.size()<k) {
      selected.insert(i);
    } else {
      multiset<int, greater<int>>::iterator biggest = selected.begin();
      if(i < *biggest){
        selected.erase(biggest);
        selected.insert(i);
      }
    }
  }
}

int main() {
  vector<int> a = {4,5,1,6,2,7,3,8};
  multiset<int, greater<int>> selected;
  findk(a, 4, selected);
  for(auto& i: selected)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
