class FreqStack {
public:
    unordered_map<int, stack<int>> hashstk;
    unordered_map<int, int> freq;
    int mx = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        hashstk[++freq[val]].push(val); //将val push进哈希表中的栈
        mx = max(mx, freq[val]); //求出最高频率
    }
    
    int pop() {
        int t = hashstk[mx].top(); //取出哈希表内栈的最外面的元素
        hashstk[mx].pop(); //弹栈
        freq[t]--; //弹出后频率减1
        if (hashstk[mx].empty()) mx--; //如果最高频元素弹光了，那么频次减1
        return t; //返回栈最外面的元素
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */