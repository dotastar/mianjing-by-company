#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int d):data(d), next(NULL){};
};

void deleteNode(Node *head, Node *d) {
  if(head == NULL || d == NULL) return;
  if(d->next == NULL){// is tail
    if(d == head) {
      head = NULL;
    } else {
      Node *p = head;
      while(p->next != d) p = p->next;
      p->next = NULL;
    }
    delete d;

  } else {
    Node *t = d->next;
    d->data = t->data;
    d->next = t->next;
    delete t;
  }
}

void printNode(Node *head) {
  for(Node *p = head; p != NULL; p = p->next) {
    cout<<p->data<<endl;
  }
}

int main(){
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  n1->next = n2;
  n2->next = n3;

  deleteNode(n1, n1);
  printNode(n1);
  
  return 0;
}
