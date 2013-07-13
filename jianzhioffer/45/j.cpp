#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int d):data(d), next(nullptr){}
};

int josephuse1(int n , int m){
  if( n < 1 || m < 1) return 0;
  Node *head = new Node(0);
  Node *p = head;
  for(int i = 1; i < n; ++i){
    p->next = new Node(i);
    p = p->next;
  }
  p->next = head;
  Node *prev = p;
  Node *current = head;
  while(current != current->next){
    for(int i = 0; i < m-1; ++i){
      current = current->next;
      prev = prev->next;
    }
    prev->next = current->next;
    delete current;
    current = prev->next;
  }
  return current->data;
  
}
int josephuse2(int n, int m) {
  if( n < 1 || m < 1) return 0;
  int result = 0;
  for(int i = 2; i <= n; ++i) {
    result = (result+m)%i;
  }
  return result;
}
int main() {
  cout<<josephuse1(5, 3)<<endl;;
  cout<<josephuse2(5, 3)<<endl;;
  return 0;
}

