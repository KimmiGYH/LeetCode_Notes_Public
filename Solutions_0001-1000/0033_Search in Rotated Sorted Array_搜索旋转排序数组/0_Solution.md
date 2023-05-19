# 33_Search in Rotated Sorted Array_搜索旋转排序数组 (Medium)

## 解法一：分段二分查找

- 首先二分找到满足 $nums[mid] \ge nums[0]$ 的最后一个数的下标，将 $[l, r]$ 更新为 $[mid, r]$

- 然后更新下标：
  - 如果 $target \ge nums[0]$，$l = 0$，而 $r$ 就是上面二分求出来的 $r$
  - 如果 $target < nums[0]$，则 $l$ 是下半段的起点，为 $r + 1$，而 $r$ 为右端点

- 最后找到大于等于 $target$ 的第一个数的下标，返回索引值。

**复杂度分析**
- 时间复杂度：$O(\log{n})$
- 空间复杂度：$O(1)$
