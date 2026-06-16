/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  void solve(vector<int>temp,Node* root,vector<vector<int>> &ans){
      if(!root){
          return;
      }
      temp.push_back(root->data);
      if(!root->left&&!root->right) {ans.push_back(temp);return;}
      solve(temp,root->left,ans);
      solve(temp,root->right,ans);
      temp.pop_back();
  }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        solve({},root,ans);
        return ans;
    }
};