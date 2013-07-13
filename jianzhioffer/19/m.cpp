#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int d):data(d), left(NULL), right(NULL){};
};

void mirror_tree(Node *root) {
  if( root == NULL) return;
  swap(root->left, root->right);
  mirror_tree(root->left);
  mirror_tree(root->right);
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

  mirror_tree(a1);
  return 0;
}
