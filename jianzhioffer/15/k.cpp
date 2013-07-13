#include <iostream>

using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int d):data(d), next(NULL){};
};
void printk(Node *head, int k){
  Node *p1 = head, *p2 = head;
  for(int i = 0; i < k; ++i) {
    if(p1 != NULL) p1 = p1->next;
    else {
      cerr<<"less than K"<<endl;
      return;
    }
  }
  while(p1 != NULL){
    p1 = p1->next;
    p2 = p2->next;
  }
  cout<<p2->data<<endl;
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

  printk(n9, 4);
  return 0;
}
