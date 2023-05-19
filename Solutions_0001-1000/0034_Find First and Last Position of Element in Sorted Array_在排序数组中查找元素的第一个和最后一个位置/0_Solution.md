# 34_Find First and Last Position of Element in Sorted Array_在排序数组中查找元素的第一个和最后一个位置 (Medium)

## 解法一：两次整数二分

思路：使用两种算法模版的差异，首先找出大于等于 $target$ 的最小的数的位置，然后找出小于等于 $target$ 的最大的数的位置。

**时间复杂度**：

- 两次二分时间复杂度为 $O(log⁡n)$。

**空间复杂度**：

- 仅需要常数的额外空间。
