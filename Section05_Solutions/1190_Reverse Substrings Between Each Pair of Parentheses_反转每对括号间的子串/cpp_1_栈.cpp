class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string res;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                stk.push(res);
                res = "";
            }
            else if (c == ')') {
                reverse(res.begin(), res.end());
                res = stk.top() + res;
                stk.pop();
            }
            else {
                if (c >= 'a' && c <= 'z')
                    res = res + c;
            }
        }
        return res;
    }
};