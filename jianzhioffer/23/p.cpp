#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int d): data(d), left(nullptr), right(nullptr){};
};

void print(Node *root){
  vector<Node*> next_level;
  if(root != NULL) next_level.push_back(root);
  while(!next_level.empty()) {
    vector<Node*> temp;
    for(auto& i: next_level) {
      if(i->left != nullptr) temp.push_back(i->left);
      if(i->right != nullptr) temp.push_back(i->right);
      cout<<i->data<<" ";
    }
    next_level = temp;
  }
}
int main() {
  Node *n1 = new Node(8);
  Node *n2 = new Node(6);
  Node *n3 = new Node(10);
  Node *n4 = new Node(5);
  Node *n5 = new Node(7);
  Node *n6 = new Node(9);
  Node *n7 = new Node(11);
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;
  n3->right = n7;

  print(n1);
  return 0;
}
