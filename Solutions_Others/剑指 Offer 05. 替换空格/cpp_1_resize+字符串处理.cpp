class Solution {
public:
    string replaceSpace(string s) {
        int size = s.length(); //old
        int cnt = 0;
        for (auto c : s) {
            if (c == ' ') cnt ++;
        }
        s.resize(size + 2 * cnt);
        int len = s.length(); //new
        for (int i = size - 1, j = len - 1; i < j; i--, j--) {
            if (s[i] != ' ') s[j] = s[i];
            else {
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            }
        }
        return s;
    }
};

// ----------------2023年5月29日----------------

class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                cnt ++;
        }
        s.resize(s.length() + 2 * cnt);
        for (int i = n - 1, j = s.length() - 1; i >= 0 && j >= 0; i--) {
            if (s[i] != ' ') {
                s[j--] = s[i];
            } else {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            }
        }
        return s;
    }
};