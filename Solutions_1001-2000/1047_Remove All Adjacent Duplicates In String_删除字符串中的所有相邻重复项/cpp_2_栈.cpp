// 自己写的
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        stack<char> stk;
        for (char& x : s) {
            if (stk.empty() || x != stk.top())
                stk.push(x);
            else if (x == stk.top())
                stk.pop();
        }
        while (!stk.empty()) {
                char t = stk.top();
                res.insert(res.cbegin(), t);
                stk.pop();
            }
        return res;
    }
};

// 另一个写法Carl版本

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            } else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};