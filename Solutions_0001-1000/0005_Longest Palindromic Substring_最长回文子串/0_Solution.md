# 5_Longest Palindromic Substring_最长回文子串 (Medium)

## 解法一：中心扩展法 $O(n^2)$

分奇数/偶数。

- 我们知道传统的验证回文串的方法就是两个两个的对称验证是否相等，那么对于找回文字串的问题，就要以每一个字符为中心，向两边扩散来寻找回文串，这个算法的时间复杂度是 $O(n^2)$

- 要注意奇偶情况，由于回文串的长度可奇可偶，比如 "bob" 是奇数形式的回文，"noon" 就是偶数形式的回文，两种形式的回文都要搜索
  - 对于奇数形式的，我们就从遍历到的位置为中心，向两边进行扩散：`l = i - 1, r = i + 1;`
  - 对于偶数情况，我们就把当前位置和下一个位置当作偶数行回文的最中间两个字符，然后向两边进行搜索：`l = i, r = i + 1;`

## 解法二：动态规划

跟 LeetCode 132.Palindrome Partitioning II 的解法很类似

- 维护一个二维数组 $dp$，其中 $dp[i][j]$ 表示字符串区间 $[i, j]$ 是否为回文串；
- 当 $j = i$ 时，只有一个字符，肯定是回文串；
- 如果是回文字符串，需要判断 $s[i]$ 是否等于 $s[j]$；
- 除了判断 $[i]$ 和 $s[j]$ 相等之外，还要判断如果只有两个字符，即 $j - i < 2$ 时，或者 $||$ $dp[i + 1][j - 1]$ 为真，就是回文串；

通过以上分析，可以写出递推式如下：

```cpp
for (int j = 0; j < n; ++j) {
    dp[j][j] = true;
    for (int i = 0; i < j; ++i) {
        if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
            dp[i][j] = true;
    }
}
```

## 解法三：动态规划（参考LC132题）

[花花酱 LeetCode 132. Palindrome Partitioning II](https://youtu.be/kTCymFbU2ok)

**第一次动态规划：**

- 状态表示：用 $valid$ 数组判断 $s[i...j]$ 是否是回文串；
- 状态转移：$valid[i][j]$ 是回文串当且仅当$s[i]$ 等于 $s[j]$ 并且 $s[i+1...j-1]$ 是回文串；
- 边界情况：循环长度 $l$ 从 $2$ 到 $n$，$j = i + l - 1$ 进行循环，也即如果 $s[i...j]$ 的长度小于等于 $2$，则 $valid[i][j] = (s[i] == s[j])$ 且 $valid[i + 1][j - 1]$;

```cpp
// valid[i][j] = 1 if s[i~j] is palindrome, otherwise 0
vector<vector<int>> valid(n, vector<int>(n, 1));

for (int l = 2; l <= n; ++l)
    for (int i = 0, j = i + l - 1; j < n; ++i, ++j)
        valid[i][j] = s[i] == s[j] && valid[i + 1][j - 1];
```
