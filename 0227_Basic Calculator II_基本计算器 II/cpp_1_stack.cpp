#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    stack<int> num;
    stack<char> op;

    int calculate(string s) {
        // 记录运算符的优先级
        unordered_map<char, int> priority;
        priority['+'] = priority['-'] = 1;
        priority['*'] = priority['/'] = 2;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ')  continue;
        }
        
    }
};