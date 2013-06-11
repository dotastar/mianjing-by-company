#include <iostream>
#include <bitset>
#include <ctime>

using namespace std;

const int N = 10000000;
int main(){
  bitset<N> s;
  int num = 0;
  clock_t t = clock();
  while(cin>>num) s.set(num);
  for(int i = 0; i < N; ++i) {
    if(s.test(i)) cout<<i<<"\n";
  }
  cerr<<"time:"<<clock()-t<<endl;
}
