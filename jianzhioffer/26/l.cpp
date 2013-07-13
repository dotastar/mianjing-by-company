#include <iostream>
#include <vector>


using namespace std;

struct Node {
  int data;
  Node *next;
  Node *sibling;
  Node(int d):data(d), next(nullptr), sibling(nullptr){};
};

Node * copy_list(Node *head) {
  if(head == nullptr) return nullptr;

  Node *p = head;
  while(p != nullptr){
    Node *t = new Node(p->data);
    t->next = p->next;
    p->next = t;
    p = t->next;
  }

  p = head;
  while(p != nullptr) {
    if(p->sibling != nullptr){
      p->next->sibling = p->sibling->next;
    }
    p = p->next->next;
  }

  Node *p_src = head;
  Node *result = p_src->next;
  Node *p_dst = result;
  while(p_src != nullptr) {
    p_src->next = p_dst->next;
    p_src = p_src->next;
    if(p_dst->next != nullptr) {
      p_dst->next = p_dst->next->next;
      p_dst = p_dst->next;
    } 
  }
  
  return result;
}

void print_list(const Node *head) {
  const Node *p = head;
  while(p != nullptr) {
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
}

int main() {
  Node *a1 = new Node(1);
  Node *a2 = new Node(2);
  Node *a3 = new Node(3);
  Node *a4 = new Node(4);
  Node *a5 = new Node(5);
  a1->next = a2;
  a1->sibling = a3;
  a2->next = a3;
  a2->sibling = a5;
  a3->next = a4;
  a4->next = a5;
  a4->sibling = a2;
  print_list(a1);
  print_list(copy_list(a1));
  return 0;
}
