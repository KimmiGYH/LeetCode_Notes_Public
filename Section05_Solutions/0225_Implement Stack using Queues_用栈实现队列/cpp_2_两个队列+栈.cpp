class MyStack {
public:
    queue<int> q, tmp;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while(q.size() > 1) tmp.push(q.front()), q.pop();
        int x = q.front();
        q.pop();
        while (tmp.size()) q.push(tmp.front()), tmp.pop();
        return x;
    }
    
    int top() {
        while(q.size() > 1) tmp.push(q.front()), q.pop();
        int x = q.front();
        q.pop();
        tmp.push(x);
        while (tmp.size()) q.push(tmp.front()), tmp.pop();
        return x;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */