class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else {
                if (stk.empty()) return false;
                if (s[i] == ')' && stk.top() != '(') return false;
                if (s[i] == ']' && stk.top() != '[') return false;
                if (s[i] == '}' && stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

// -------------------------------------------------

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (s[i] == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            }
            else if (s[i] == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            }
            else {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

// -----------------2023年5月31日-------------------

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char& x : s) {
            if (x == '(' || x == '[' || x == '{')
                stk.push(x);
            else if (x == ')') {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            } else if (x == ']') {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            } else {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};