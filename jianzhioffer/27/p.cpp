#include <iostream>
#include <vector>


using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int d):data(d), left(nullptr), right(nullptr){};
};

void dfs(Node *root, Node*& prev, Node*& head){
  if(root == nullptr) return;
  Node *left = root->left;
  Node *right = root->right;
  dfs(left, prev, head);
  root->left = nullptr;
  root->right = nullptr;
  if(prev != nullptr){
    prev->right = root;
    root->left = prev;
  } else {
    head = root;
  }
  prev = root;
  dfs(right, prev, head);
}

Node *convert(Node *root){
  Node * head = nullptr, *prev = nullptr;
  dfs(root, prev, head);
  return head;
}

void print(Node *head){
  Node *p = head, *prev = nullptr;
  while(p != nullptr) {
    cout<<p->data<<" ";
    prev = p;
    p = p->right;
  }
  cout<<endl;
  p = prev;
  while(p != nullptr) {
    cout<<p->data<<" ";
    p = p->left;
  }
  cout<<endl;
}
int main() {
  Node *a1 = new Node(10);
  Node *a2 = new Node(6);
  Node *a3 = new Node(14);
  Node *a4 = new Node(4);
  Node *a5 = new Node(8);
  Node *a6 = new Node(12);
  Node *a7 = new Node(16);

  a1->left = a2;
  a1->right = a3;
  a2->left = a4;
  a2->right = a5;
  a3->left = a6;
  a3->right = a7;

  print(convert(a1));
  return 0;
}
