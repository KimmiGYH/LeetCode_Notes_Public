class Solution {
    unordered_map<char, int> cnt;
    int n;
public:
    bool check(unordered_map<char, int>& sum) {
        for (auto x : cnt) {
            char c = x.first;
            if (cnt[c] - sum[c] > n/4) 
                return false;
        }
        return true;
    }             

    int balancedString(string s) {
        n = s.length();
        for (char& c : s)
            cnt[c] ++;

        bool flag = true;
        for (auto x : cnt) {
            if (x.second != n/4)
                flag = false;
        }
        if (flag == true) return 0;

        int res = INT_MAX;
        unordered_map<char, int> sum;
        for (int i = 0, j = 0; i < n; i ++) {
            sum[s[i]] ++;
            while (check(sum)) {
                res = min(res, i - j + 1);
                sum[s[j ++]] --;
            }
        }
        return res;
    }
};