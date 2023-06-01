class Solution {
public:
    stack<int> stk;
    void eval(string& x) {
        int num2 = stk.top(); stk.pop();
        int num1 = stk.top(); stk.pop();
        if      (x == "+")
            stk.push(num1 + num2);
        else if (x == "-")
            stk.push(num1 - num2);
        else if (x == "*")
            stk.push(num1 * num2);
        else if (x == "/")
            stk.push(num1 / num2);
    }

    int evalRPN(vector<string>& tokens) {
        unordered_set<string> S = {"+", "-", "*", "/"};
        for (string& x : tokens) {
            if (S.count(x))
                eval(x);
            else
                stk.push(stoi(x));
        }
        return stk.top();
    }
};