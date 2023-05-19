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
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                if (s == "+")       a += b;
                else if (s == "-")  a -= b;
                else if (s == "*")  a *= b;
                else                a /= b;
                stk.push(a);
            }
            else stk.push(stoi(s));// stoi: string to int
        }
        return stk.top();
    }
};
