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
    int minValue(Node* root) {
        // code here
        Node* temp = root;
        while(root->left){
            temp = root->left;
            root = root->left;
        }
        return temp->data;
    }
};