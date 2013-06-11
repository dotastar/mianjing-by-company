#include <stdio.h>

int bs1(int a[], int n, int t){
  int low = 0, high = n-1;
  while(low <= high) {
    //printf("%d-%d\n", low, high);
    int mid = low + (high-low)/2;
    if(a[mid] < t) low = mid + 1;
    else if(a[mid] > t) high = mid -1;
    else {
      if(mid == 0 || a[mid-1] != a[mid])
        return mid;
      else high = mid - 1;
    }
  }
  return -1;
}
int main() {
  int a1[] = {1,1,2,3,3,5,8,8,8,10,27,27,29,31,31};
  printf("%d\n", bs1(a1, sizeof(a1)/sizeof(int), 8));
}
