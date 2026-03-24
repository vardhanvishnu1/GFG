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
    int lengthOfLoop(Node *head) {
        // code here
        if(head==NULL) return NULL;
        Node* slow=head;
        Node* fast=head;
        bool flag=false;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag = true;
                break;
            }
        }
        
        Node* ans = NULL;
        if(flag){
            Node* temp=head;
            while(temp!=slow){
                temp=temp->next;
                slow=slow->next;
            }
            ans = temp;
        }
        int cnt = 1;
        if(ans){
            Node* temp = ans->next;
            while(temp!=ans){
                temp = temp->next;cnt++;
            }
        }
        else return 0;
        return cnt;
    }
};