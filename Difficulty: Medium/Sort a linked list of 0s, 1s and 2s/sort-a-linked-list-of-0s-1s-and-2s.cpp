/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zd = new Node(-1);
        Node* od = new Node(-1);
        Node* td = new Node(-1);
        Node* z = zd;
        Node* o = od;
        Node* t = td;
        
        Node* temp = head;
        while(temp){
            if(temp->data==0) {z->next = new Node(0);z=z->next;}
            if(temp->data==1) {o->next = new Node(1);o=o->next;}
            if(temp->data==2) {t->next = new Node(2);t=t->next;}
            temp = temp->next;
        }
        if(zd->next) head = zd->next;
        else if(od->next) head = od->next;
        else head = td->next;
        temp = head;
        if(od->next) z->next = od->next;
        else z->next = td->next;
        if(td->next) o->next = td->next;
        return head;
    }
};