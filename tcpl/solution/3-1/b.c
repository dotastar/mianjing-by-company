#include <stdio.h>

int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n-1;

  while(low < high) {
    mid = (low + high) / 2;
    if(v[mid] < x) {
      low = mid+1;
    } else {
      high = mid;
    }
  }

  if (low == high) return v[low];
  else             return -1;
  
}

int main()
{
  int v[] = {1,2,3,4,5};
  printf("%d = 3", binsearch(3, v, 5));
  return 0;
}
