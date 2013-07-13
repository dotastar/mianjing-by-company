#include <iostream>
#include <stack>

using namespace std;

class MinStack{
 private:
  stack<int> data;
  stack<int> min_stack;
 public:
  int min();
  void push(int element);
  int pop();
};

int MinStack::min(){
  return min_stack.top();
}

void MinStack::push(int element){
  data.push(element);

  if(min_stack.empty()) {
    min_stack.push(element);
  } else {
    if(min_stack.top() >= element)
      min_stack.push(element);
  }
}

int MinStack::pop(){
  int result = data.top();
  data.pop();
  if( result == min_stack.top())min_stack.pop();;
  return result;
}
int main() {
  MinStack s;
  s.push(3);
  s.push(5);
  s.push(1);
  cout<<s.min()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.min()<<endl;
  return 0;
}
