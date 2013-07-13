#include <stack>
#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
};

void print_reverse_iterative(Node *head) {
  stack<Node*> s;
  for(Node *p = head; p != NULL; p = p->next) {
    s.push(p);
  }
  while(!s.empty()){
    cout<<s.top()->data<<endl;
    s.pop();
  }
}

void print_reverse_recursive(Node *head) {
  if(head == NULL) return;
  print_reverse_recursive(head->next);
  cout<<head->data<<endl;
}

int main(){
  Node *n1 = new Node;
  n1->data = 1;
  Node *head = n1;
  Node *n2 = new Node;
  n2->data = 2;
  n1->next = n2;
  Node *n3 = new Node;
  n3->data = 3;
  n2->next = n3;
  n3->next = NULL;
  print_reverse_iterative(head);
  print_reverse_recursive(head);
  return 0;
}
