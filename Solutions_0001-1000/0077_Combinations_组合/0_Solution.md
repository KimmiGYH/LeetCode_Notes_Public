# 77. Combinations_组合 (Medium)



##### DFS + Backtracking 深度优先搜索 + 回溯  $O(C_{n}^{k} * k)$

深度优先搜索，一共枚举 `k` 层，`k` 表示当前还需要选几个数。

由于这道题要求组合数，不考虑数的顺序，所以我们需要再记录一个值 `start`，表示当前数可以从第几个数开始选，来保证所选的数递增。

`dfs(n, k, start)`
比如前面已经选到 5 了，下次选的时候应从 6 开始选。k 表示当前还可以选几个数。
`dfs(n, k - 1, start + 1)`

##### 时间复杂度分析：

一共有 $C_{n}^{k}$ 个方案，另外记录每个方案时还需要  $O(k)$ 的时间，所以时间复杂度是是 $O(C_{n}^{k} * k)$。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0077_Combinations_%E7%BB%84%E5%90%88/solve.png)