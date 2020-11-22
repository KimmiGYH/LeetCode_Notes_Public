#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    stack<int> num;
    stack<char> op;

    void cal()
    {
        int b = num.top(); num.pop();
        int a = num.top(); num.pop();
        char c = op.top(); op.pop();
        int r;
        if (c == '+')  r = a + b;
        else if (c == '-')  r = a - b;
        else if (c == '*')  r = a * b;
        else r = a / b;
        num.push(r);
    }

    
    int calculate(string s) {
        // 记录运算符的优先级
        unordered_map<char, int> priority;
        priority['+'] = priority['-'] = 1;
        priority['*'] = priority['/'] = 2;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ')  continue;
            if (isdigit(c))
            {
                int x = 0, j = i;
                while (j < s.size() && isdigit(s[j]))
                    x = x * 10 + (s[j++] - '0');
                i = j - 1;
                num.push(x);
            }
            else
            {
                while (op.size() && priority[op.top()] >= priority[c]) cal();
                op.push(c);
            }
        }
        while (op.size())  cal();
        return num.top();
    }
};