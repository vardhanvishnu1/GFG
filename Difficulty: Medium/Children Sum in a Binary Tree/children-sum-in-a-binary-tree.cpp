/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
  bool solve(Node *root){
      if(!root) return true;
      if(!root->left&&!root->right) return true;
      int curr = 0;
      if(root->left) curr+=root->left->data;
      if(root->right) curr+=root->right->data;
      if(root->data!=curr) return false;
      return solve(root->left)&solve(root->right);
  }
  
    bool isSumProperty(Node *root) {
        // code here
        return solve(root);
    }
};