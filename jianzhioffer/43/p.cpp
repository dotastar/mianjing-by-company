#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int kDiceFace = 6;

void print(int n){
  vector<vector<int>> p(2, vector<int>(n*kDiceFace+1, 0));
  for(int i = 1; i <= kDiceFace; ++i){
    p[0][i] = 1;
  }
  int flag = 0;
  for(int i = 2; i <= n; ++i){
    for(int x = 0; x < i; ++x)
      p[1-flag][x] = 0;
    
    for(int j = i; j <= i*kDiceFace; ++j) {
      p[1-flag][j] = 0;
      for(int k = 1; k <= kDiceFace && j-k >= 0; ++k){
        p[1-flag][j] += p[flag][j-k];
      }
    }
    flag = 1- flag;
  }
  double total = pow(6, n);
  for(int i = 0; i <= n*kDiceFace; ++i) {
    if(p[flag][i] != 0) cout<<i<<"="<<p[flag][i]/total*100<<"%"<<endl;
  }
}

int main() {
  print(3);
  return 0;
}

