#include <iostream>

using namespace std;

int main() {
  cout<<"sizeof(bool)="<<sizeof(bool)<<endl;
  cout<<"sizeof(char)="<<sizeof(char)<<endl;
  cout<<"sizeof(short)="<<sizeof(short)<<endl;
  cout<<"sizeof(int)="<<sizeof(int)<<endl;
  cout<<"sizeof(long)="<<sizeof(long)<<endl;
  cout<<"sizeof(long long)="<<sizeof(long long)<<endl;
  cout<<"sizeof(float)="<<sizeof(float)<<endl;
  cout<<"sizeof(double)="<<sizeof(double)<<endl;
  cout<<"sizeof(wchar_t)="<<sizeof(wchar_t)<<endl;
  int n = 0;
  int * p_int = &n;
  cout<<"sizeof(int *)="<<sizeof(int *)<<endl;
  cout<<"sizeof(p_int)="<<sizeof(p_int)<<endl;
  cout<<"sizeof(n)="<<sizeof(n)<<endl;
  double d = 0;
  double *p_double = &d;
  cout<<"sizeof(double *)="<<sizeof(double *)<<endl;
  cout<<"sizeof(p_double)="<<sizeof(p_double)<<endl;
  cout<<"sizeof(d)="<<sizeof(d)<<endl;
  enum color{red, green, blue};
  cout<<"sizeof(color)="<<sizeof(color)<<endl;
  cout<<"sizeof(green)="<<sizeof(green)<<endl;
}
