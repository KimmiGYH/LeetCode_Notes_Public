# 108. Convert Sorted Array to Binary Search Tree_将有序数组转换为二叉搜索树 (Easy)



[花花酱 LeetCode 108 Convert Sorted Array to Binary Search Tree](https://youtu.be/O5BSAhg4n0M)



**时间复杂度是 $O(n)$**

因为每一个节点都需要 变为 `node` 加入到 `BST`, 所以是 $O(n)$

 **空间复杂度是 $O(logn)$**

拿 `dfs` 来说, 由于是深度搜索, 同一时间内, 只有一条路径在 recursive call 的 `stack` 上, 由于是一个 `BST`, 所以树高是 `logn`, 路径最长是 `logn`。如果考虑 Tree 自身的存储 就是 O(n)。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0108_Convert%20Sorted%20Array%20to%20Binary%20Search%20Tree_%E5%B0%86%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E8%BD%AC%E6%8D%A2%E4%B8%BA%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91/solve.png)