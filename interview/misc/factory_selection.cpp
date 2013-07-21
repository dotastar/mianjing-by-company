//http://blog.csdn.net/julianxiong/article/details/7381214
#include <iostream>
#include <vector>

using namespace std;

int selection(const vector<int>& pos, vector<int>& selection) {
  int n = pos.size();
  int m = selection.size();
  vector<vector<int> > a(m, vector<int>(n,0));
  
}
int main() {
  vector<int> pos = {0,4,5,10,12,18,27,30, 31,38,39,47};
  vector<int> selection(3);
  cout<<"distance sum is "<<selection(pos, selection)<<endl;
  copy(selection.begin(), selection.end(), ostream_iterator<int>(stdout, ","));
  return 0;
}
