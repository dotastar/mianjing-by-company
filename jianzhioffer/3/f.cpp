#include <iostream>

using namespace std;

bool find(int* a, int m, int n, int t){
  if(a == NULL || m < 0 || n < 0) return false;
  int row = 0, col = n-1;
  while(row < m && col >=0){
    if(a[row*n+col] > t) col--;
    else if(a[row*n+col] < t) row++;
    else return true;
  }
  return false; 
}
int main(){
  int a[4][4] = {{1,2,8,9},
                 {2,4,9,12},
                 {4,7,10,13},
                 {6,8,11,15}};
  cout<<find(&a[0][0], 4, 4, 5)<<"== 0"<<endl;
  cout<<find(&a[0][0], 4, 4, 7)<<"== 1"<<endl;
  return 0;
}
