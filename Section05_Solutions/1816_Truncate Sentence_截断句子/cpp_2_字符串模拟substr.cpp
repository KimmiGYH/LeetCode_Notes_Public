class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.length(), cnt = 0, idx = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == ' ' || i == n) {
                cnt ++;
                if (cnt == k) {
                    idx = i;
                    break;
                }
            }
        }
        return s.substr(0, idx);
    }
};
