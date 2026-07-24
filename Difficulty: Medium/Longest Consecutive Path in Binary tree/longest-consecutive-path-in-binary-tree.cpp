/* Structure of Binary Tree Node
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
  void solve(int& ans,int prev,int cnt,Node* root){
      if(!root) {return;}
      if(prev==-1||root->data-prev==1){
          cnt++;
      }
      else{
          prev = root->data;
          cnt = 1;
      }
      ans = max(ans,cnt);
      solve(ans,root->data,cnt,root->left);
      solve(ans,root->data,cnt,root->right);
  }
    int longestConsecutive(Node* root) {
        // code here
        int ans = 0;
        solve(ans,-1,0,root);
        if(ans==1) return -1;
        return ans;
    }
};