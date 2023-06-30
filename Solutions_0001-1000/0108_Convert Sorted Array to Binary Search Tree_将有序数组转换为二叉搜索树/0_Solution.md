# 108. Convert Sorted Array to Binary Search Tree_将有序数组转换为二叉搜索树 (Easy)



[花花酱 LeetCode 108 Convert Sorted Array to Binary Search Tree](https://youtu.be/O5BSAhg4n0M)



**时间复杂度是 $O(n)$**

因为每一个节点都需要 变为 `node` 加入到 `BST`, 所以是 $O(n)$

 **空间复杂度是 $O(logn)$**

拿 `dfs` 来说, 由于是深度搜索, 同一时间内, 只有一条路径在 recursive call 的 `stack` 上, 由于是一个 `BST`, 所以树高是 `logn`, 路径最长是 `logn`。如果考虑 Tree 自身的存储 就是 O(n)。
