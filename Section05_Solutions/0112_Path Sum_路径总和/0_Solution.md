# 112. Path Sum_路径总和 (Easy)

**(递归) $O(n)$**

递归，自顶向下从根节点往叶节点走，每走过一个节点，就让 `sum` 减去该节点的值，则如果走到某个叶节点时，`sum` 恰好为 `0`，则说明从根节点到这个叶节点的路径上的数的和等于 `sum`。

只要找到一条满足要求的路径，递归即可返回。

##### 时间复杂度分析

每个节点仅被遍历一次，且递归过程中维护 `sum` 的时间复杂度是 `O(1)`，所以总时间复杂度是 `O(n)`。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0112_Path%20Sum_%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C/solve.png)