#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                if (s == "+")       b += a;
                else if (s == "-")  b -= a;
                else if (s == "*")  b *= a;
                else                b /= a;
                stk.push(b);
            }
            else stk.push(stoi(s));// stoi: string to int
        }
        return stk.top();
    }
};
