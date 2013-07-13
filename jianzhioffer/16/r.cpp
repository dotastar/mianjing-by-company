#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int d):data(d), next(NULL){};
};
Node * reverse(Node *head){
  if(head == NULL || head->next == NULL) return NULL;
  Node *p1 = head, *p2 = head->next;
  p1->next = NULL;
  while(p2 != NULL) {
    Node *t = p2->next;
    p2->next = p1;
    p1 = p2;
    p2 = t;
  }
  return p1;
}
void print(const Node *head){
  for (const Node *p = head; p != NULL; p = p->next) cout<<p->data<<" ";
  cout<<endl;
}
int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  Node *n8 = new Node(8);
  Node *n9 = new Node(9);
  n9->next = n8;
  n8->next = n7;
  n7->next = n6;
  n6->next = n5;
  n5->next = n4;
  n4->next = n3;
  n3->next = n2;
  n2->next = n1;

  Node *head = n9;
  print(head);
  head = reverse(n9);
  print(head);
  return 0;
}
