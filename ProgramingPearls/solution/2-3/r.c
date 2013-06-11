#include <stdio.h>
#include <stdlib.h>

void rotate1(char a[], int n, int i) {
  char t;
  int j = 0;
  int k = 0;
  char *mark = (char *)malloc(n* sizeof(char));
  for(j = 0; j < n; ++j) {
    mark[j] = 0;
  }
  for(j = 0; j < n; ++j) {
    if(mark[j] == 0) {
      t = a[j];
      int old_k = j;
      k = j+i;
      while(k != j){
        a[old_k] = a[k];
        mark[old_k] = 1;
        old_k = k;
        k += i;
        k %= n;
      }
      a[old_k] = t;
      mark[old_k] = 1;
    }
  }
  free(mark);
}

void swap(char a[], int n, int s1, int s2, int len) {
  int i = 0;
  for(; i < len; ++i) {
    char t = a[s1+i];
    a[s1+i] = a[s2+i];
    a[s2+i] = t;
  }
}

// low<--i-->|<--j-->high
void r2(char a[], int n, int low, int i, int high) {
  int j = high - low + 1 - i;
  if(i == j) swap(a, n, low, low+i, i);
  else if(i < j) {
    swap(a, n, low, low + j, i);
    r2(a, n, low, i, high - i);
  } else {
    swap(a, n, low, low + i, j);
    r2(a, n, low + j, i-j, high);    
  }
}
void rotate2(char a[], int n, int i) {
  r2(a, n, 0, i, n-1);
}

void reverse(char a[], int begin, int end){
  for(; begin < end; begin++, end--){
    char t = a[begin];
    a[begin] = a[end];
    a[end] = t;
  }
}

void rotate3(char a[], int n, int i) {
  reverse(a, 0, i-1);
  reverse(a, i, n-1);
  reverse(a, 0, n-1);
}

int main() {
  char a1[] = "abcdefghijk";
  rotate1(a1, sizeof(a1)-1, 3);
  printf("%s\n",a1);
  char a2[] = "abcdefghijk";
  rotate2(a2, sizeof(a2)-1, 3);
  printf("%s\n",a2);
  char a3[] = "abcdefghijk";
  rotate3(a3, sizeof(a3)-1, 3);
  printf("%s\n",a3);
}
