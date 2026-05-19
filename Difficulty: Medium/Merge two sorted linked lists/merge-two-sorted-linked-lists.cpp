/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* temp1 = head1;
        Node* temp2 = head2;
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        while(temp1&&temp2){
            if(temp1->data<temp2->data) {temp->next = temp1;temp1 = temp1->next;}
            else {temp->next = temp2;temp2 = temp2->next;}
            temp = temp->next;
            temp->next = NULL;
        }
        if(temp1) temp->next = temp1;
        else temp->next = temp2;
        return dummy->next;
    }
};