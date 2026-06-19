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
    void find_parent(unordered_map<Node*,Node*>&parent,Node* root){
        queue<Node*>q;
        q.push(root);
        parent[root] = NULL; 
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    Node* find_target(Node* root, int target){
        if(!root) return NULL;
        if(root->data==target) return root;
        Node* left =  find_target(root->left,target);
        if(left) return left;
        return find_target(root->right,target);
    }
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*>parent;
        find_parent(parent,root);
        Node* target_node = find_target(root,target);
        unordered_set<Node*>visited;
        queue<Node*>q;
        q.push(target_node);
        visited.insert(target_node);
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                Node* node = q.front();
                q.pop();
                if(parent[node]&&!visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
                if(node->left&&!visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);
                }
                if(node->right&&!visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }
            }
            ans++;
        }
        return ans-1;
    }
};