/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  void solve(int& ans,int k,int currentSum,Node *root,map<int,int>&mp){
     if(!root) return;
     currentSum+=root->data;
     if(currentSum==k) ans++;
     if(mp.find(currentSum-k)!=mp.end()) ans+=mp[currentSum-k];
     mp[currentSum]++;
     solve(ans,k,currentSum,root->left,mp);
     solve(ans,k,currentSum,root->right,mp);
     mp[currentSum]--;
     
  }
    int countAllPaths(Node *root , int k) {
        // code here
        int ans = 0 ;
        map<int,int>mp;
        solve(ans,k,0,root,mp);
        return ans ;
    }
};