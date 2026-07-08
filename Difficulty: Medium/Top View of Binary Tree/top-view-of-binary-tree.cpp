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
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            auto [node,pos] = q.front();
            q.pop();
            if(!mp.count(pos)) mp[pos] = node->data;
            if(node->left) q.push({node->left,pos-1});
            if(node->right) q.push({node->right,pos+1});
        } 
        for(auto el : mp) ans.push_back(el.second);
        return ans;
    }
};