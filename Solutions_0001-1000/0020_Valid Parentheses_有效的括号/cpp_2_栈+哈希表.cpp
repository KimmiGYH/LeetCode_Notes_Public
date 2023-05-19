class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 == 1) return false; //奇数返回false
        
        unordered_map<char, char> hash = {
            {')', '('}, //{男生，女生}
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char c : s) {
            if (hash.count(c)) {
                if (stk.empty() || stk.top() != hash[c]) return false;
                stk.pop();
            }
            else stk.push(c);
        }
        return stk.empty();
    }
};