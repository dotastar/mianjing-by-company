#include <stdio.h>


int bs1(int a[], int low, int high, int t){
  if (low <= high) {
    //printf("%d-%d\n", low, high);
    int mid = low + (high-low)/2;
    if(a[mid] < t) return bs1(a, mid + 1, high, t);
    else if(a[mid] > t) return bs1(a, low, mid - 1, t);
    else {
      return mid;
    }
  } else 
    return -1;
}

int main() {
  int a1[] = {1,1,2,3,3,5,8,8,8,10,27,27,29,31,31};
  printf("%d\n", bs1(a1, 0, sizeof(a1)/sizeof(int) - 1, 8));
}
