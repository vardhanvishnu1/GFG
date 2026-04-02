/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
  Node* head;
  int sz ;
    myStack() {
        // Initialize your data members
        head = NULL;
        sz = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return sz==0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }

    void pop() {
        // Removes the top element of the stack
        if(sz>0) {head = head->next;sz--;}
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(sz==0) return -1;
        return head->data;
    }

    int size() {
        // Returns the current size of the stack.
        return sz;
    }
};