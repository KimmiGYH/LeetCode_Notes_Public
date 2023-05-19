# 1234_Replace the Substring for Balanced String_替换子串得到平衡字符串

## 解法一：同向双指针（滑动窗口）

- 根据题意，如果在待替换子串**之外**的任意字符的出现次数超过 $\frac{n}{4}$，那么无论怎么替换，都无法使这个字符的出现次数等于 $\frac{n}{4}$ 。
- 比如 `W E [W Q Q X] E E`，$\frac{n}{4}$ 为 $2$，但窗口外有 $3$ 个 `E`，那窗口内怎么改都没法使得总的 `E` 为 $2$

- 反过来说，如果在待替换子串**之外**的任意字符的出现次数都不超过 $\frac{n}{4}$，那么可以通过替换，使 $s$ 为平衡字符串，即每个字符的出现次数均为 $\frac{n}{4}$。

- 这可以用同向双指针（长度不固定的滑动窗口）实现。

- 对于本题，设子串的左右端点为 $left$ 和 $right$，枚举 $right$，如果子串外的任意字符的出现次数都不超过 $\frac{n}{4}$，则说明从 $left$ 到 $right$ 的这段子串可以是待替换子串，用其长度 $right − left + 1$ 更新答案的最小值，并向右移动 $left$，缩小子串长度。


### 参考：
- 灵茶山艾府：https://leetcode.cn/problems/replace-the-substring-for-balanced-string/solutions/2108358/tong-xiang-shuang-zhi-zhen-hua-dong-chua-z7tu/

- Huifeng Guan: https://youtu.be/XSGa1lP9vD8?t=837


```cpp
class Solution {
    unordered_map<char, int> cnt;
    int n;
public:
    bool check(unordered_map<char, int>& sum) {
        for (auto x : cnt) {//查看四个字符
            char c = x.first;
            //窗口外的字符词频是否 > n/4，这样子窗口内怎么魔改都不行
            //比如 W E [W Q Q X] E E，n/4为2，但窗口外有3个E，那窗口内没法改使得总的E为2
            if (cnt[c] - sum[c] > n/4) 
                return false;
        }
        return true;
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

        int res = INT_MAX;
        unordered_map<char, int> sum;
        for (int i = 0, j = 0; i < n; i ++) { //枚举子串右端点i
            sum[s[i]] ++;
            while (check(sum)) {
                res = min(res, i - j + 1);
                sum[s[j ++]] --;
            }
        }
        return res;
    }
};
```