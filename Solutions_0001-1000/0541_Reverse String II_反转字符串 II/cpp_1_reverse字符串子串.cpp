class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2*k) {
            int l = i, r = min(i + k - 1, (int)s.length() - 1);
            reverse(s.begin() + l, s.begin() + r + 1);
        }
        return s;
    }
};

// 或者左闭右开，把右界变成开区间

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2*k) {
            int l = i, r = min(i + k, (int)s.length());
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};

// 把右界直接分开写

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2*k) {
            if (i + k <= s.length()) {
                reverse(s.begin() + i, s.begin() + i + k);
            } else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};