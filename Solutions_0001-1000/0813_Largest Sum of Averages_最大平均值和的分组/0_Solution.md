# 813_Largest Sum of Averages_最大平均值和的分组

## 解法一：动态规划

[花花酱 LeetCode 813. Largest Sum of Averages](https://youtu.be/IPdShoUE9z8?t=895)

- 状态表示：$dp[k][i]$ 把前 $n$ 个元素划分成 $K$ 组 能够取得的最大值是多少
- 属性：最大值
- 状态转移方程：`for j in k-1, …, i-1`
  $$
  dp[k][i] = max(dp[k – 1][j] + (sum[i] - sums[j]) / (i – j));
  $$

**时间复杂度：** $O(kn^2)$

**空间复杂度：** $O(kn)$
