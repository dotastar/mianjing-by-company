#include <iostream>
#include <vector>

using namespace std;

void find_num(vector<int>& a) {
  int n = a.size();
  int t = 0;
  for(auto& e: a){
      t ^= e;
  }
  int i = 0;
  for(; i < 32; ++i) {
    if(t & (1<<i)) break;
  }
  //cout<<i<<endl;
  int r1 = 0, r2 = 0;
  for(auto& e: a){
    if((e & (1<<i)) == 0){
      r1 ^= e;
    }else{
      r2 ^= e;
    }
  }
  cout<<r1<<" "<<r2<<endl;
}

int main() {
  vector<int> a = {2,4,3,6,3,2,5,5};
  find_num(a);
  return 0;
}

