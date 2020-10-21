# 209. Minimum Size Subarray Sum (Medium)

Given an array of **n** positive integers and a positive integer **s**, find the minimal length of a **contiguous** subarray of which the sum ≥ **s**. If there isn't one, return 0 instead.

**Example:** 

**Input:** `s = 7, nums = [2,3,1,2,4,3]`
**Output:** 2
**Explanation:** the subarray `[4,3]` has the minimal length under the problem constraint.

**Follow up:**

If you have figured out the *O*(*n*) solution, try coding another solution of which the time complexity is *O*(*n* log *n*).


# [209\. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)

难度中等475

给定一个含有 **n** 个正整数的数组和一个正整数 **s ，**找出该数组中满足其和 **≥ s** 的长度最小的 **连续** 子数组，并返回其长度**。**如果不存在符合条件的子数组，返回 0。

**示例：**

**输入：**`s = 7, nums = [2,3,1,2,4,3]`
**输出：**2
**解释：**子数组 `[4,3]` 是该条件下的长度最小的子数组。

**进阶：**

*   如果你已经完成了 *O*(*n*) 时间复杂度的解法, 请尝试 *O*(*n* log *n*) 时间复杂度的解法。


# 题目大意
给定⼀个整型数组和⼀个数字 s，找到数组中最短的⼀个连续⼦数组，使得连续⼦数组的数字之和
sum>=s，返回最短的连续⼦数组的返回值。
