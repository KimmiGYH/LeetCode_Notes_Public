class Solution {
public:
    string makeGood(string s) {
        string stk;
        int offset = 'a' - 'A';
        for (int i = 0; i < s.length(); i++) {
            stk += s[i];
            int n = stk.size();
            if (n >= 2 && (stk[n-1] + offset == stk[n-2] || stk[n-1] - offset == stk[n-2]))
                stk.resize(n-2);
        }
        return stk;
    }
};