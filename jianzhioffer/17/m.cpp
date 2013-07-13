#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int d):data(d), next(NULL){};
};

void print(const Node *head){
  for (const Node *p = head; p != NULL; p = p->next) cout<<p->data<<" ";
  cout<<endl;
}

Node *merge(Node *h1, Node *h2) {
  if (h1 == NULL && h2 == NULL)  return NULL;
  
  Node *p1 = h1, *p2 = h2, *h3 = NULL, *p3 = NULL;
  while(p1 != NULL && p2 != NULL) {
    if( p1->data < p2->data) {
      if(h3 == NULL) {
        h3 = p1;
      } else {
        p3->next = p1;
      }
      p3 = p1;
      p1 = p1->next;
      p3->next = NULL;
    } else {
      if(h3 == NULL) {
        h3 = p2;
      } else {
        p3->next = p2;
      }
      p3 = p2;
      p2 = p2->next;
      p3->next = NULL;
    }
  }
  if(p1 != NULL) {
    p3->next = p1;
  } else if (p2 != NULL) {
    p3->next = p2;
  }
  return h3;
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
  n1->next = n3;
  n3->next = n5;
  n5->next = n7;
  n7->next = n9;
  n2->next = n4;
  n4->next = n6;
  n6->next = n8;

  Node *h1 = n1, *h2 = n2;
  print(h1);
  print(h2);
  Node *head = merge(h1, h2);
  print(head);

  return 0;
}
