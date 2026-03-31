class myStack {
  public:
  vector<int>s;
        int mx_sz;
        int sz = 0;
        
    myStack(int n) {
        // Define Data Structures
        mx_sz=n;
        s.reserve(n);
    }

    bool isEmpty() {
        // check if the stack is empty
        return sz==0;
    }

    bool isFull() {
        // check if the stack is full
        return sz==mx_sz;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(!isFull()){
            s.push_back(x);
            sz++;
        }
    }

    void pop() {
        // removes an element from the top of the stack
        if(!isEmpty()){
            s.pop_back();
            sz--;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(s.size()>0){
            return s.back();
        }
        return -1;
    }
};