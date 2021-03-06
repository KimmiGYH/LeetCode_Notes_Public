# 1329_Sort the Matrix Diagonally_将矩阵按对角线排序

## 解法一：哈希表 + 优先队列

- 对于处于同一个对角线的元素来说，它的行号减列号值是相同的，因此可以用该差值将矩阵的元素按照对角线分组。
- 考虑到快速查找，使用哈希表。题目中要求对同一个对角线的元素按照从小到大排序，考虑使用优先队列（小顶堆）。
- 这样，我们按照对角线为分组加入元素，每当同一个对角线中加入一个元素，就会按照从小到大排序。之后我们按照哈希表检索，依次从堆顶输出元素。

**时间复杂度：**

- $O(M*N*logD)$，$D$ 是对角线的长度 $D = min(M, N)$

**空间复杂度：**

- $O(MN)$
