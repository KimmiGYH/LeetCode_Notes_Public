class Solution {
public:
    stack<int> num;
    stack<char> op;

    void eval() {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int x = 0;
        if (c == '+')       x = a + b;
        else if (c == '-')  x = a - b;
        else if (c == '*')  x = a * b;
        else                x = a / b;
        num.push(x);
    }

    int calculate(string s) {
        int res = 0;
        
        unordered_map<char, int> priority {
            {'+', 1}, {'-', 1},
            {'*', 2}, {'/', 2},
        };
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
            // else if (c == '(') op.push(c);
            // else if (c == ')') {
            //     while (op.top() != '(') eval();
            //     op.pop();
            // } 
            else {
                while (op.size() && priority[c] <= priority[op.top()]) eval();
                op.push(c);
            }
        }
        while (op.size()) eval();
        return num.top();
    }
};