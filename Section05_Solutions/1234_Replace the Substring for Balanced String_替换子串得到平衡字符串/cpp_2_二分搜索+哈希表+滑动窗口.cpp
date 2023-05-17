// Huifeng Guan: https://youtu.be/XSGa1lP9vD8?t=837
class Solution {
    unordered_map<char, int> cnt;
    int n;
public:
    bool check(int k, string& s) {
        unordered_map<char, int> sum;
        for (int i = 0; i < n; i ++) {
            sum[s[i]] += 1;
            if (i >= k) {
                sum[s[i - k]] -= 1;//sum存的滑窗里的词频
            }
            bool flag = 1;
            for (auto x : cnt) {//查看四个字符
                char c = x.first;
                //窗口外的字符词频是否 > n/4，这样子窗口内怎么魔改都不行
                //比如 W E [W Q Q X] E E，n/4为2，但窗口外有3个E，那窗口内没法改使得总的E为2
                if (cnt[c] - sum[c] > n/4) {
                    flag = false;
                    break;
                }
            }
            if (flag == 1)
                return true;
        }
        return false;
    }

    int balancedString(string s) {
        n = s.length();
        for (char& c : s)
            cnt[c] ++;
        //判断已经是Balanced String的情况
        bool flag = 1;
        for (auto x : cnt) {
            if (x.second != n/4)
                flag = 0;
        }
        if (flag == 1) return 0;
        //开始二分
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, s)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};