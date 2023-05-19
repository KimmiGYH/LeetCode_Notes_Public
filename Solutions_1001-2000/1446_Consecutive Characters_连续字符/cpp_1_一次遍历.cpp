class Solution {
public:
    int maxPower(string s) {
        int res = 1, cnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                cnt++;
                res = max(res, cnt);
            } else
                cnt = 1;//重置
        }
        return res;
    }
};