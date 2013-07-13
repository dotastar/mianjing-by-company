#include <iostream>
#include <stack>


using namespace std;

template<typename T>
class MyQueue{
 public:
  MyQueue(){};
  ~MyQueue(){};
  void push(const T& item);
  T pop();
  
 private:
  stack<T> stack1;
  stack<T> stack2;
};

template<typename T>
void MyQueue<T>::push(const T& item){
  stack1.push(item);
}
template<typename T>
T MyQueue<T>::pop(){
  if(stack2.empty()){
    while(!stack1.empty()){
      stack2.push(stack1.top());
      stack1.pop();
    }
  }
  if(!stack2.empty()){
    T t = stack2.top();
    stack2.pop();
    return t;
  }else
    throw new exception;
}

int main() {
  MyQueue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  cout<<q.pop()<<endl;
}
