# [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) (Medium)

Find the **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Example 1:**

**Input:** `[3,2,1,5,6,4]` and k = 2
**Output:** 5

**Example 2:**

**Input:** `[3,2,3,1,2,4,5,5,6]` and k = 4
**Output:** 4

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ array's length.

# [215\. 数组中的第K个最大元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

难度中等746

在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

**示例 1:**

**输入:** `[3,2,1,5,6,4] 和` k = 2
**输出:** 5

**示例 2:**

**输入:** `[3,2,3,1,2,4,5,5,6] 和` k = 4
**输出:** 4

**说明:**

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

# 题目大意
**快速选择算法**：
找出数组中第 K ⼤的元素。这⼀题⾮常经典。可以⽤ O(n) 的时间复杂度实现。