#include <iostream>

using namespace std;

double pow1(double base, int exp){
  if(exp == 0) return base;
  bool neg = false;
  if(exp < 0) {
    neg = true;
    exp = -exp;
  }
  double r = 1;
  for(int i = 0; i < exp; ++i)
    r *= base;
  if(neg) {
    if(r <= 0.000001 && r >= -0.000001) throw new exception;
    r = 1/r;
  }
  return r;
}

double pow2(double base, int exp){
  if(exp == 0) return 1;
  bool neg = false;
  if(exp < 0) {
    neg = true;
    exp = -exp;
  }
  double r = 0;
  if(exp == 1) r = base;
  else if(exp % 2 == 0) {
    double t = pow2(base, exp/2);
    r = t*t;
  } else {
    double t = pow2(base, exp/2);
    r = t*t*base;
  }
  if(neg) {
    if(r <= 0.000001 && r >= -0.000001) throw new exception;
    r = 1/r;
  }
  return r;
  
}


int main(){
  cout<<"2^3="<<pow1(2, 3)<<endl;
  cout<<"2^-2="<<pow1(2, -2)<<endl;
  cout<<"2^0="<<pow1(2, 0)<<endl;
  cout<<"2^6="<<pow2(2, 6)<<endl;
  cout<<"2^-3="<<pow2(2, -3)<<endl;
  cout<<"2^0="<<pow2(2, 0)<<endl;
  return 0;
}
