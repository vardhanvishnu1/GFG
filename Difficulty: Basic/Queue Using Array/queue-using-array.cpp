class myQueue {

  public:
  vector<int>q;
  int mx_sz ;
    myQueue(int n) {
        // Define Data Structures
        q.reserve(n);
        mx_sz = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return q.size()==0;
    }

    bool isFull() {
        // check if the queue is full
        return q.size()==mx_sz;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(!isFull()) q.push_back(x);
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(!isEmpty()) q.erase(q.begin());
    }

    int getFront() {
        // Returns the front element of the queue.
        if(!isEmpty()) return q[0];
        return -1;
    }

    int getRear() {
        // Return the last element of queue
        if(!isEmpty()) return q.back();
        return -1;
    }
};