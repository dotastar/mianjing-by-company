#include <iostream>
#include <vector>


using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int d):data(d), left(nullptr), right(nullptr){};
};

void dfs(Node *root, vector<Node*> path, int sum, int target){
  if (root == nullptr) return;
  if(sum + root->data == target){
    //print path
    for(auto& i : path) cout<<i->data<<" ";
    cout<<root->data<<endl;
  }
  path.push_back(root);
  dfs(root->left, path, sum+root->data, target);
  dfs(root->right, path, sum+root->data, target);
}
void find_path(Node *root, int target) {
  vector<Node*> path;
  dfs(root, path, 0, target);
}

int main() {
  Node *a1 = new Node(10);
  Node *a2 = new Node(5);
  Node *a3 = new Node(12);
  Node *a4 = new Node(4);
  Node *a5 = new Node(7);
  a1->left = a2;
  a1->right = a3;
  a2->left = a4;
  a2->right = a5;

  find_path(a1, 22);
  return 0;
}
