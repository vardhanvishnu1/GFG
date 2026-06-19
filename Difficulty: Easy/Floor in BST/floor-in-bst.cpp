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
    void solve(Node*& prev,Node* root, int k){
        if(!root) return ;
        if(root->data<=k) { prev = root;solve(prev,root->right,k);}
        else solve(prev,root->left,k);
    }
    int findMaxFork(Node* root, int k) {
        // code here
        Node* prev = NULL;
        solve(prev,root,k);
        if(!prev) return -1;
        return prev->data;
    }
};