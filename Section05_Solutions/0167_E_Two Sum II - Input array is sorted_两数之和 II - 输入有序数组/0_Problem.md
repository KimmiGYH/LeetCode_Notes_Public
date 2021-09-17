# 167. Two Sum II - Input array is sorted (Easy)

Given an array of integers that is already ***sorted in ascending order***, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

**Note:**

*   Your returned answers (both index1 and index2) are not zero-based.
*   You may assume that each input would have *exactly* one solution and you may not use the *same* element twice.

**Example 1:**

**Input:** numbers = \[2,7,11,15\], target = 9
**Output:** \[1,2\]
**Explanation:** The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

**Example 2:**

**Input:** numbers = \[2,3,4\], target = 6
**Output:** \[1,3\]

**Example 3:**

**Input:** numbers = \[-1,0\], target = -1
**Output:** \[1,2\]

**Constraints:**

*   `2 <= nums.length <= 3 * 104`
*   `-1000 <= nums[i] <= 1000`
*   `nums` is sorted in **increasing order**.
*   `-1000 <= target <= 1000`


# [167\. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

难度简单415

给定一个已按照***升序排列*** 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2*。*

**说明:**

*   返回的下标值（index1 和 index2）不是从零开始的。
*   你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

**示例:**

**输入:** numbers = \[2, 7, 11, 15\], target = 9
**输出:** \[1,2\]
**解释:** 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。


# 题目大意
找出两个数之和等于 target 的两个数字，要求输出它们的下标。注意⼀个数字不能使⽤ 2 次。下标从⼩到⼤输出。假定题⽬⼀定有⼀个解。
