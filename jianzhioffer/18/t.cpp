#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int d):data(d), left(NULL), right(NULL){};
};


bool my_equal(Node *a, Node *b){
  if(b == NULL) return true;
  if(a == NULL) return false;
  return a->data == b->data && my_equal(a->left, b->left) && my_equal(a->right, b->right);
}

bool has(Node *a, Node *b){
  if(a == NULL && b != NULL) return false;
  if(a == NULL && b == NULL) return true;
  return my_equal(a, b) || has(a->left, b) || has(a->right, b);
}
  
int main() {
  Node *a1 = new Node(8);
  Node *a2 = new Node(8);
  Node *a3 = new Node(7);
  Node *a4 = new Node(9);
  Node *a5 = new Node(2);
  Node *a6 = new Node(4);
  Node *a7 = new Node(7);
  a1->left = a2;
  a1->right = a3;
  a2->left = a4;
  a2->right = a5;
  a5->left = a6;
  a5->right = a7;

  Node *b1 = new Node(8);
  Node *b2 = new Node(9);
  Node *b3 = new Node(2);
  b1->left = b2;
  b1->right = b3;
  
  cout<<has(a1, b1)<<endl;

  return 0;
}
