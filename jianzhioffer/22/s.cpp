#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool valid(const vector<int>& push_seq, const vector<int>& pop_seq) {
  if(pop_seq.size() != push_seq.size())
    return false;
  size_t n = pop_seq.size();
  vector<int> test_stack;
  int i = 0;//index for pop_seq
  int j = 0;//index for push_seq
  while(i < n || j < n){
    if(find(test_stack.begin(), test_stack.end(), pop_seq[i]) == test_stack.end()){
      test_stack.push_back(push_seq[j++]);
    } else {
      if(test_stack.back() != pop_seq[i]) return false;
      test_stack.pop_back();
      ++i;
    }
  }
  if(i == n && j == n)
    return true;
  else return false;
}

int main() {
  vector<int> push_seq = {1,2,3,4,5};
  vector<int> pop_seq1 = {4,5,3,2,1};
  vector<int> pop_seq2 = {4,3,5,1,2};
  cout<<valid(push_seq, pop_seq1)<<" should be true"<<endl;
  cout<<valid(push_seq, pop_seq2)<<" should be false"<<endl;
  return 0;
}
