class Solution {
public:
    void eval(stack<int>& num, stack<char>& op) {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int x = 0;
        if (c == '+')       x = a + b;
        else if (c == '-')  x = a - b;
        // else if (c == '*')  x = a * b;
        // else                x = a / b;
        num.push(x);
    }
    
    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        unordered_map<char, int> pr;
        pr['+'] = pr['-'] = 1;
        pr['*'] = pr['/'] = 2;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') continue;
            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j++] - '0');
                num.push(x);
                i = j - 1;
            }
            else if (c == '(') op.push(c);
            else if (c == ')') {
                while (op.top() != '(') eval(num, op);
                op.pop();
            } else {
                if (!i || s[i-1] == '(' || s[i-1] == '+' || s[i-1] == '-')
                    num.push(0);// 特殊处理符号和正号
                while (op.size() && op.top() != '(') eval(num, op);
                op.push(c);
            }
        }
        while (op.size()) eval(num, op);
        return num.top();
    }
};