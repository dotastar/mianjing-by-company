#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int d):data(d), next(nullptr){}
};

int find_len(Node *h){
  Node *p = h;
  int len = 0;
  while(p != nullptr){
    p = p->next;
    ++len;
  }
  return len;
}
int find_common(Node *h1, Node *h2) {
  int len1 = find_len(h1);
  int len2 = find_len(h2);
  Node *p1 = h1, *p2 = h2;
  if(len1 > len2) {
    for(int i = 0; i < len1-len2; ++i)
      p1 = p1->next;
  } else {
     for(int i = 0; i < len2-len1; ++i)
      p2 = p2->next;
  }
  
  while(p1 != nullptr && p2 != nullptr){
    if(p1 == p2) return p1->data;
    p1 = p1->next;
    p2 = p2->next;
  }
  return 0;
}

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  n1->next = n2;
  n2->next = n3;
  n3->next = n6;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;
  cout<<find_common(n1, n4)<<endl;
  return 0;
}

