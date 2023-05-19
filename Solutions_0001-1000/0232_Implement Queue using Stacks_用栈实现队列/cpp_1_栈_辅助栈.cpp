class MyQueue {
public:
    stack<int> stk, tmp;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        while (!stk.empty()) tmp.push(stk.top()), stk.pop();
        int x = tmp.top();
        tmp.pop();
        while (!tmp.empty()) stk.push(tmp.top()), tmp.pop();
        return x;
    }
    
    int peek() {
        while (!stk.empty()) tmp.push(stk.top()), stk.pop();
        int x = tmp.top();
        while (!tmp.empty()) stk.push(tmp.top()), tmp.pop();
        return x;
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */