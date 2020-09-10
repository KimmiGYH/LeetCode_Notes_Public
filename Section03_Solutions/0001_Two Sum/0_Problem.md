# [1. Two Sum (Easy)](https://leetcode.com/problems/two-sum/)

Given an array of integers `nums` and and integer `target`, return *the indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly\* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.



**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1]
```

**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
```

**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-109 <= nums[i] <= 10^9`
- `-109 <= target <= 10^9`
- **Only one valid answer exists.**





# [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

难度简单

给定一个整数数组 `nums` 和一个目标值 `target`，请你在该数组中找出和为目标值的那 **两个** 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

**示例:**

```
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
```



# 题目大意



在数组中找到 2 个数之和等于给定值的数字，结果返回 2 个数字在数组中的下标。