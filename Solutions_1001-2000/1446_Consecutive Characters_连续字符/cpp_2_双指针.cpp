class Solution {
public:
    int maxPower(string s) {
        int n = s.length(), res = 1;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            res = max(res, j - i);
            i = j - 1; //j退回一步
        }
        return res;
    }
};


class Solution {
public:
    int maxPower(string s) {
        int n = s.length(), res = 1;
        for (int i = 0; i < n; ) { //这么写可以省去 j 回退一步的麻烦
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
};