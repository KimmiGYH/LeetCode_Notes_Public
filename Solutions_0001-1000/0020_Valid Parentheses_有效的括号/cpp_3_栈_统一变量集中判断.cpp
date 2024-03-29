#include <iostream>
#include <cassert>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
            else {
                if (stack.empty()) return false;

                char c = stack.top();
                stack.pop();

                char match;
                if (s[i] == ')')  match = '(';
                else if (s[i] == ']')  match = '[';
                else { // s[i] == '}'
                    assert(s[i] == '}'); // 排除其他字符
                    match = '{';
                }
                
                if (c != match)
                    return false;
            }
        }
        // if (stack.size() != 0)
        //     return false;
        // return true;
        return stack.empty();//直接写这行
    }
};