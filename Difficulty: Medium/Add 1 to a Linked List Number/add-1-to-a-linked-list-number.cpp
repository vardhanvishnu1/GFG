/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseList(Node* head) {
       Node* prev = NULL;
       Node* curr = head;
       Node* curr_nxt;
       while(curr){
           curr_nxt = curr->next;
           curr->next=prev;
           prev = curr;
           curr = curr_nxt;
       }
       return prev;
   }
    Node* addOne(Node* head) {
        // Your Code here
        head = reverseList(head);
        Node* temp = head;Node* prev = NULL;
        bool flag = true;
        while(temp){
            int curr = (temp->data);
            if(flag) curr++;
            temp->data = curr%10;
            if(curr>9) flag = true;
            else flag = false;
            prev = temp;
            temp = temp->next;
            
        }
        if(flag){
            if(prev) {prev->next = new Node(1);prev = prev->next;}
        }
        prev = reverseList(head);
        return prev;
        // return head of list after adding one
    }
};