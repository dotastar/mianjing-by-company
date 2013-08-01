#include <stdio.h>

int find1(int a[], int n){
  int d = 0, c = 0;// d is number, c is count
  int i = 0;
  for(i = 0; i < n; ++i){
    if (c == 0){
      d = a[i];
      c = 1;
    } else {
      if( d == a[i]) ++c;
      else --c;
    }
  }
  return d;
}
void find3(int a[], int n, int b[], int m){
  int c[3] = {0};// c is count
  int i, j;
  for(i = 0; i < n; ++i){
    for(j = 0; j < m; ++j){
      if (c[j] == 0){
        b[j] = a[i];
        c[j] = 1;
        break;
      }
    }
    if( j != m) continue;
    for(j = 0; j < m; ++j){
      if( b[j] == a[i]) {
        ++c[j];
        break;
      }
    }
    if( j == m){
      for(j = 0; j < m; ++j){
         --c[j];
      }
    }
  }
}

int main() {
  int a[] = {5,2,3,3,4,1,3,3,3};
  printf("find %d, should be 3\n", find1(a, sizeof(a)/sizeof(a[0])));
  int a2[] = {5,2,3,3,8,2,7,5,2,5,3,3,3};
  int b[3] = {-1, -1, -1};
  find3(a2, sizeof(a2)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
  printf("%d, %d, %d,  should be 2, 5, 3\n", b[0], b[1], b[2]);

}
