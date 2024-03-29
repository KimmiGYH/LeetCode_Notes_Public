# 1337_The K Weakest Rows in a Matrix_矩阵中战斗力最弱的 K 行

## 解法一：二分查找

- 题目描述中有一条重要的保证：军人总是排在一行中的靠前位置，也就是说 $1$ 总是出现在 $0$ 之前。
- 因此，我们可以通过二分查找的方法，找出一行中最后的那个 $1$ 的位置。将其二分出来的位置下标值 $+1$，这便是这一行里 $1$ 的个数；如果这第 $i$ 行没有 $1$，那么令其值为 $0$，下标为 $i$。
- 当我们得到每一行的战斗力后，我们可以将它们全部放入一个小根堆中，并不断地取出堆顶的元素 $k$ 次，这样我们就得到了最弱的 $k$ 行的索引。

**复杂度分析**

- 时间复杂度：$O(m \log n + k \log m)$：
  - 我们需要 $O(m \log n)$ 的时间对每一行进行二分查找。
  - 我们需要 $O(m)$ 的时间建立小根堆。
  - 我们需要 $O(k \log m)$ 的时间从堆中取出 $k$ 个最小的元素。

- 空间复杂度：$O(m)$，即为堆需要使用的空间。

