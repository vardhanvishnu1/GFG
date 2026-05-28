/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
  
    void solve(int& l,int pos,vector<int>&ans,Node* root){
        if(!root) {
            return;
        }
        ans[pos+abs(l)]+=root->data;
        solve(l,pos-1,ans,root->left);
        solve(l,pos+1,ans,root->right);
    }
    void length(int& l,int& r,int pos,Node* root){
        if(!root) return ;
        l = min(l,pos);
        r = max(pos,r);
        length(l,r,pos-1,root->left);
        length(l,r,pos+1,root->right);
    }
    vector<int> verticalSum(Node* root) {
        // code here
        int l = 0;
        int r =0;
        length(l,r,0,root);
        int sz = r-l+1;
        vector<int>ans(sz,0);
        solve(l,0,ans,root);
        return ans;
    }
};