class MyStack {
public:
    queue<int> que, q_backup; // 辅助队列，用来备份

    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        while (que.size() - 1) { // 将 que1 导入 que2，但要留下最后一个元素
            int t = que.front();
            que.pop();
            q_backup.push(t);
        }
        int res = que.front(); // 留下的最后一个元素就是要返回的值
        que.pop();
        que = q_backup;             // 再将 q_backup 赋值给 que
        while (!q_backup.empty()) { // 清空 que
            q_backup.pop();
        }
        return res;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
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