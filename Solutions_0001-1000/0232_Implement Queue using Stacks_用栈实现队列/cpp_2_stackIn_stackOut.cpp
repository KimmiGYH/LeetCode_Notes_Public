class MyQueue {
public:
    stack<int> stackIn;
    stack<int> stackOut;

    MyQueue() {

    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        // 只有当stackOut为空的时候，再从stackIn里导入数据（导入stackIn全部数据）
        if (stackOut.empty()) {
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result = stackOut.top();
        stackOut.pop();
        return result;
    }
    
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        stackOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }
    
    bool empty() {
        return stackIn.empty() && stackOut.empty();
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