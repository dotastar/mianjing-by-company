#include <iostream>

using namespace std;
enum direction {
  kUp, kDown, kLeft, kRight
};

void print(int a[4][4], int m, int n){
  int row = 0, col = 0;
  direction d = kRight;
  while(1){
    cout<<a[row][col]<<" ";
    a[row][col] = -1;
    if((col >= n-1 || a[row][col+1] == -1)
       &&(row >= m-1 || a[row+1][col] == -1)
       &&(col <= 0 || a[row][col-1] == -1)
       &&(row <= 0 || a[row-1][col] == -1))
      break;
    if(d == kRight) {
      if(col >= n-1 || a[row][col+1] == -1){
        d = kDown;
        ++row;
      } else {
        ++col;
      }
    } else if(d == kDown) {
      if(row >= m-1 || a[row+1][col] == -1){
        d = kLeft;
        --col;
      } else {
        ++row;
      }
    } else if(d == kLeft) {
      if(col <= 0 || a[row][col-1] == -1){
        d = kUp;
        --row;
      } else {
        --col;
      }
    } else if(d == kUp) {
      if(row <= 0 || a[row-1][col] == -1){
        d = kRight;
        ++col;
      } else {
        --row;
      }
    } else {
      cerr<<"error"<<endl;;
    }
  }
}

int main() {
  int a[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  print(a, 4 ,4);
}
