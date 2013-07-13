#include <iostream>

using namespace std;

struct BTNode {
  int data;
  BTNode *left;
  BTNode *right;
  BTNode(int d):data(d), left(NULL), right(NULL){};
};

BTNode* build(BTNode *root, int preorder_array[], int preorder_begin, int preorder_end,int inorder_array[], int inorder_begin, int inorder_end) {
  //cout<<"pre"<<preorder_begin<<"->"<<preorder_end<<"||"<<"in"<<inorder_begin<<"->"<<inorder_end<<endl;
  if(preorder_begin > preorder_end || inorder_begin > inorder_end) return root;

  if(root == NULL) {
    root = new BTNode(preorder_array[preorder_begin]);
    //cout<<root->data<<"-"<<endl;
  }

  int i = inorder_begin;
  for(; i <= inorder_end; ++i){
    if(preorder_array[preorder_begin] == inorder_array[i]) break;
  }
  int left_size = i - inorder_begin;
  root->left = build(root->left, preorder_array, preorder_begin+1,preorder_begin+left_size, inorder_array, inorder_begin, i - 1); 
  root->right = build(root->right, preorder_array, preorder_begin+left_size+1,preorder_end, inorder_array, i+1, inorder_end);
  return root;
}

void print_postorder(BTNode *root) {
  if(root == NULL) return;
  print_postorder(root->left);
  print_postorder(root->right);
  cout<<root->data<<",";
}

int main() {
  int preorder[] = {1, 2, 4, 7, 3, 5, 6,8};
  int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
  print_postorder(build(NULL, preorder, 0, 7, inorder, 0, 7));
  return 0;
}
