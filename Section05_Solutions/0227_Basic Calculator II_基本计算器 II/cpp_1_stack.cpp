#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    stack<int> nums;
    stack<char> ops;

    void cal()
    {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char c = ops.top(); ops.pop();
        int r;
        if (c == '+')  r = a + b;
        else if (c == '-')  r = a - b;
        else if (c == '*')  r = a * b;
        else r = a / b;
        nums.push(r);
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
                nums.push(x);
            }
            else
            {
                while (ops.size() && priority[ops.top()] >= priority[c]) cal();
                ops.push(c);
            }
        }
        while (ops.size())  cal();
        return nums.top();
    }
};