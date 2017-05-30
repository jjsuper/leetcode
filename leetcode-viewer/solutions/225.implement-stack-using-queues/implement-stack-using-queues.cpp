class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        myqueue.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(myqueue.size()==1) return myqueue.pop();
        
        for(int i=0;i<myqueue.size()-1;++i)
        {
            int x;
            x=myqueue.front();
            myqueue.pop();
            myqueue.push(x);
        }
        
        myqueue.pop();
    }

    // Get the top element.
    int top() {
        int x;
            
       // if(myqueue.size()==1) return myqueue.front();
        
        for(int i=0;i<myqueue.size();++i)
        {
            x=myqueue.front();
            myqueue.pop();
            myqueue.push(x);
        }
        
        return x;
    }

    // Return whether the stack is empty.
    bool empty() {
        return myqueue.empty();
    }
private:
    std::queue<int> myqueue;
};