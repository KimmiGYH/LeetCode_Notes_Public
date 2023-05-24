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