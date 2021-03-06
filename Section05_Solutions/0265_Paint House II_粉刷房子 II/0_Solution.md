# 265.Paint-House-II $O(n*mlogm)$

1. 本题比较正常的DP解法就是令 $dp[i][j]$ 表示刷完第 $i$ 个房子、且第 $i$ 个房子刷第 $j$ 种漆，此时所需要的全部代价。

2. 此题可以做到 $O(m*n)$ 的解法。这是因为我们在确定第 $i$ 座房子刷第 $j$ 种漆后，本质上只需要关心前面第 $i-1$ 座房子刷完漆的最小代价是什么，再加上 $costs[i][j]$ 即可。

3. 唯一需要考虑的就是：如果给第 $i-1$ 座房子刷漆的最小代价所用的油漆也是第 $j$ 种漆，和第 $i$ 个房子所用的油漆重合了怎么办？遇到这种情况，我们需要同时也记录下刷完第 $i-1$ 座房子**第二最小代价**及其油漆种类就行。

4. 一个比较粗暴的方法就是，考虑刷完第 $i-1$ 座房子之后，将所有的 $dp[i-1][n](n = 0, 1, 2, ..., n-1)$ 排个序，记录下最小的两个值以及对应的油漆编号，比如说 $a$ 和 $b$。

   所以计算 $dp[i][j]$ 时，如果 $j!=a$，则 $dp[i][j] = dp[i-1][a] + costs[i][j]$；否则我们就要采用备选方案，即 $dp[i][j] = dp[i-1][b] + costs[i][j]$

5. 因为我们不能肯定最后一座房子会刷什么颜色，所以最后的答案是在 $dp[m-1][n](n = 0, 1, 2, ..., n-1)$ 挑选最小值。

- 此题和 `1289. Minimum Falling Path Sum II` 本质一模一样。
