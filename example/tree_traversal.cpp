// http://en.wikipedia.org/wiki/Tree_traversal

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Node {
  string value;
  Node *left;
  Node *right;
  Node(string data): value(data), left(nullptr), right(nullptr){}
};

void inorder_recursive(Node *root){
  if(root == nullptr) return;
  inorder_recursive(root->left);
  cout<<root->value<<" ";
  inorder_recursive(root->right);
}

void inorder_iterative(Node *root){
  stack<Node*> parent_stack;
  while(!parent_stack.empty() || root != nullptr) {
    if(root != nullptr) {
      parent_stack.push(root);
      root = root->left;
    } else {
      root = parent_stack.top();
      parent_stack.pop();
      cout<<root->value<<" ";
      root = root->right;
    }
  }
}

void inorder_morris(Node *root) {
  Node *current = root;
  while(current != nullptr) {
    if(current->left == nullptr){
      cout<<current->value<<" ";
      current = current->right;
    } else {
      Node *prev = current->left;
      while(prev->right != nullptr && prev->right != current){
        prev = prev->right;
      }
      if(prev->right == nullptr){
        prev->right = current;
        current = current->left;
      } else {
        prev->right = nullptr;
        cout<<current->value<<" ";
        current = current->right;
      }
    }
  }
}

void preorder_recursive(Node *root){
  if(root == nullptr) return;
  cout<<root->value<<" ";
  preorder_recursive(root->left);
  preorder_recursive(root->right);
}

void preorder_iterative(Node *root){
  stack<Node*> parent_stack;
  while(!parent_stack.empty() || root != nullptr) {
    if(root != nullptr) {
      cout<<root->value<<" ";
      parent_stack.push(root->right);
      root = root->left;
    } else {
      root = parent_stack.top();
      parent_stack.pop();
    }
  }
}

void postorder_recursive(Node *root){
  if(root == nullptr) return;
  postorder_recursive(root->left);
  postorder_recursive(root->right);
  cout<<root->value<<" ";
}

void postorder_iterative(Node *root){
  if( root == nullptr) return;
  stack<Node*> node_stack;
  node_stack.push(root);
  Node *prev = nullptr;
  while(!node_stack.empty()) {
      Node *current = node_stack.top();
    if(prev == nullptr || prev->left == current || prev->right == current) {
      if(current->left != nullptr) {
        node_stack.push(current->left);
      } else if(current->right != nullptr) {
          node_stack.push(current->right);
        }
    } else if( current->left == prev ) {
        if(current->right != nullptr) {
          node_stack.push(current->right);
        }
    } else {
      cout<<current->value<<" ";
      node_stack.pop();
    }
    prev = current;
  }
}

void levelorder(Node *root){
  if( root == nullptr) return;
  queue<Node *> q;
  q.push(root);
  while(!q.empty()){
    Node *node = q.front();
    q.pop();
    cout<<node->value<<" ";
    if(node->left != nullptr){
      q.push(node->left);
    }
    if(node->right != nullptr) {
      q.push(node->right);
    }
  }
}

int main() {
  Node *root = new Node("F");
  root->left = new Node("B");
  root->right = new Node("G");
  root->left->left = new Node("A");
  root->left->right = new Node("D");
  root->left->right->left = new Node("C");
  root->left->right->right = new Node("E");
  root->right->right = new Node("I");
  root->right->right->left = new Node("H");

  cout<<"Pre-order traversal sequence: F, B, A, D, C, E, G, I, H (root, left, right)"<<endl;
  cout<<"preorder_recursive:"<<endl;
  preorder_recursive(root);
  cout<<endl;
  cout<<"preorder_iterative:"<<endl;
  preorder_iterative(root);
  cout<<endl;

  cout<<"In-order traversal sequence: A, B, C, D, E, F, G, H, I (left, root, right)"<<endl;
  cout<<"inorder_recursive:"<<endl;
  inorder_recursive(root);
  cout<<endl;
  cout<<"inorder_iterative:"<<endl;
  inorder_iterative(root);
  cout<<endl;
  cout<<"inorder_morris:"<<endl;
  inorder_morris(root);
  cout<<endl;

  cout<<"Post-order traversal sequence: A, C, E, D, B, H, I, G, F (left, right, root)"<<endl;
  cout<<"postorder_recursive:"<<endl;
  postorder_recursive(root);
  cout<<endl;
  cout<<"postorder_iterative:"<<endl;
  postorder_iterative(root);
  cout<<endl;

  cout<<"Level-order traversal sequence: F, B, G, A, D, I, C, E, H"<<endl;
  cout<<"levelorder:"<<endl;
  levelorder(root);
  cout<<endl;

}
