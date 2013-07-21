#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Direction{
  kUp,kUpLeft, kLeft, kNone
};

void lcs_length(const string& x, const string& y, vector<vector<int> >& c, vector<vector<Direction> >& b){
  int m = x.size();
  int n = y.size();
  c.resize(m+1, vector<int>(n+1, 0));
  b.resize(m+1, vector<Direction>(n+1, kNone));
  for(int i = 1; i <= m; ++i) {
    for(int j = 1; j <= n; ++j){
      if(x[i-1] == y[j-1]){
        c[i][j] = c[i-1][j-1]+1;
        b[i][j] = kUpLeft;
      } else {
        if(c[i-1][j] >= c[i][j-1]) {
          c[i][j] = c[i-1][j];
          b[i][j] = kUp;
        } else {
          c[i][j] = c[i][j-1];
          b[i][j] = kLeft;
        }
      }
    }
  }
}

void print_lcs(vector<vector<Direction> >&b, string& x, int i, int j){
  if( i == 0 || j == 0) {
    return;
  }
  if(b[i][j] == kUpLeft){
    print_lcs(b, x, i-1, j-1);
    cout<<x[i-1]<<" ";
  } else if (b[i][j] == kUp){
    print_lcs(b, x, i-1, j);
  } else if (b[i][j] == kLeft){
    print_lcs(b, x, i, j-1);
  } else {
    cout<<"error"<<endl;
  }
}

void print_c(vector<vector<int> >& c){
  for(int i = 0; i < c.size(); ++i){
    for(int j = 0; j <c[0].size(); ++j){
      cout<<c[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main() {
  string x("ABCBDAB");
  string y("BDCABA");
  vector<vector<int> > c;
  vector<vector<Direction> > b;
  lcs_length(x, y, c, b);
  print_c(c);
  print_lcs(b, x, x.size(), y.size());
  cout<<endl;
  return 0;
}
