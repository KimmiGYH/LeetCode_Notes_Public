# 0120_Triangle_三角形最小路径和

## 方法一：自下而上

![思路](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0120_Triangle_%E4%B8%89%E8%A7%92%E5%BD%A2%E6%9C%80%E5%B0%8F%E8%B7%AF%E5%BE%84%E5%92%8C/0_%E6%80%9D%E8%B7%AF.png)

```
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
```

时间复杂度 O(n^2)

1、状态定义：
`dp[i][j]` 表示从点 `(i, j)` 到底边的最小路径和。

2、状态转移：
`dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j]`

## 方法二：自下而上 降维 优化空间

在上述代码中，我们定义了一个 `N` 行 `N` 列 的 `dp` 数组（`N` 是三角形的行数）。

但是在实际递推中我们发现，计算 `dp[i][j]` 时，只用到了下一行的 `dp[i + 1][j]` 和 `dp[i + 1][j + 1]`。

因此 `dp` 数组不需要定义 `N` 行，只要定义 `1` 行就阔以啦。

所以我们稍微修改一下上述代码，将 `i` 所在的维度去掉（如下），就可以将 `O(N^2)` 的空间复杂度优化成 `O(N)` 啦～
