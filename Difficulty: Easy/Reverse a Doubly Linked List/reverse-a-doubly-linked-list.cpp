/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
       Node* pre = NULL;
       Node* curr = head;
       Node* curr_nxt;
       while(curr){
           curr_nxt = curr->next;
           curr->next = pre;
           if(pre) pre->prev = curr;
           pre = curr;
           curr = curr_nxt;
       }
       return pre;
    }
};