/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  void solve(int& ans,Node* root, int k){
     if(!root) return;
     if(root->data<=k){
         ans = root->data;
         solve(ans,root->right,k);
     }
     else solve(ans,root->left,k);
     
  }
    int findMaxFork(Node* root, int k) {
        // code here
        int ans = -1;
        solve(ans,root,k);
        return ans;
    }
};