# 1278_Palindrome Partitioning III_分割回文串 III(Hard)

## 解法一：动态规划

[花花酱 LeetCode 1278. Palindrome Partitioning III](https://youtu.be/kD6ShM6jr3g)

**第一次动态规划：**

- 状态表示：$cost[i][j]$ 表示将子字符串变成回文串的变化数
- 状态属性：Count数量
- 状态转移：$cost[i][j] = (s[i] != s[j]) + cost[i+1][j-1]$

**第二次动态规划：**

- 状态表示：$dp[i][k]$ 表示对前 $i$ 个字母分割成 $k$ 个字符串
- 状态属性：最小值
- 初始值：$dp[i][1] = cost(0, i)$
- 状态转移：$dp[i][k] = min(dp[j][k-1] + cost(j+1, i))$

**时间复杂度：** $O(n^{2}*k) <= O(n^3)$

**空间复杂度：** $O(n*k)$
