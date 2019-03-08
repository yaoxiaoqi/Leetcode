class MyQueue {
private:
    stack<int> s, peekElems;
    int size;
public:
    /** Initialize your data structure here. */
    MyQueue(): size(0){
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
        ++size;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp;
        if (size == 0) return 0;
        if (peekElems.empty()) {
            while(!s.empty()) {
                peekElems.push(s.top());
                s.pop();
            }
        }
        tmp = peekElems.top();
        peekElems.pop();
        --size;
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if (size == 0) return 0;
        if (peekElems.empty()) {
            while(!s.empty()) {
                peekElems.push(s.top());
                s.pop();
            }
        }
        return peekElems.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
