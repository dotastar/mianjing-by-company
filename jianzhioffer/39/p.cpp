#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
  int data;
  Node *left;
  Node *right;
  Node(int d):data(d), left(nullptr), right(nullptr){}
};

int find_longest_path(Node *root){
  if(root == nullptr) return 0;
  return 1 + max(find_longest_path(root->left), find_longest_path(root->right));
}

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);

  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  n5->left = n7;
  n3->right = n6;

  cout<<find_longest_path(n1)<<endl;
  return 0;
}

