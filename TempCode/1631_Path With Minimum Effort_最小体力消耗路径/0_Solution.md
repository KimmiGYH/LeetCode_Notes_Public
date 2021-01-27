# 1631_Path With Minimum Effort_最小体力消耗路径

## 解法一：二分搜索 + BFS

- 假设 minimum effort 是 $limit$，那么意味着路径上不能有高度差超过 $limit$ 的边。
- 怎么验证有没有呢？BFS 走一遍就行。从左上角向外扩展，遇到 diff 大于 $limit$ 的边就绕行，看看最终能否到达右下角。
- 成功的话，就尝试减小 $limit$；不成功的话，就尝试增大 $limit$。
- 这个时间复杂度是 $O(M*N*logH)$，$H$ 是矩阵元素的最大值。
