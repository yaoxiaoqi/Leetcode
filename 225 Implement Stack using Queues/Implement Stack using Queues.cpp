class MyStack {
private:
    int size;
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack():size(0) {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        ++size;
        for (int i = 0; i < size-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = q.front();
        q.pop();
        --size;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (empty()) {
            return -1;
        }
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
