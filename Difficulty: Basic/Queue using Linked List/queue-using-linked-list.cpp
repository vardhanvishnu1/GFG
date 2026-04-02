class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {

  public:
  Node* head;
  Node* last;
  int sz;
    myQueue() {
        // Initialize your data members
        head = NULL;
        last = NULL;
        sz=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return sz==0;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* temp = new Node(x);
        if(!head){
            head = temp;
            last = head;
            sz++;
            return;
        }
        if(last) last->next = temp;
        last = temp;
        sz++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(sz>0) {
            head = head->next;
            if(head==NULL){
                last = NULL;
            }
            sz--;
        }
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(sz==0) return -1;
        return head->data;
    }

    int size() {
        // Returns the current size of the queue.
        return sz;
    }
    
};
