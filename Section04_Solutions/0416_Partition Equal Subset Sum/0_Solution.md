# 416 Partition Equal Subset Sum

典型的背包问题，在`n`个物品中选出一定物品，填满`sum/2`的背包

`F(n, C)` 考虑将 `n` 个物品填满容量为 `C` 的背包

`F(i, c) = F(i-1, c) || F(i-1, c-w(i))`

时间复杂度：`O(n * sum/2) = O(n * sum)`
