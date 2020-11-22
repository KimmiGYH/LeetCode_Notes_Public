#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    void eval(stack<int>& num, stack<char>& op) {
        auto b = num.top(); num.pop();
        auto a = num.top(); num.pop();
        auto c = op.top(); op.pop();
        int r;
        if (c == '+')  r = a + b;
        else r = a - b;
        num.push(r);
    }

    int calculate(string s) {
        stack<int> num;
        stack<char> op;
        for (int i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (c == ' ')  continue;
            if (isdigit(c)) {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j++] - '0'); // 加括号防止溢出
                i = j - 1;
                num.push(x);
            } else if (c == '(') {
                op.push(c);
            } else if (c == ')') {
                while (op.top() != '(')  eval(num, op);
                op.pop();
            } else {
                while (op.size() && op.top() != '(')  eval(num, op);
                op.push(c);
            }
        }
        while (op.size())  eval(num, op);
        return num.top();
    }
};