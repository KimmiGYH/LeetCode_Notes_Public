# [219. Contains Duplicate II](https://leetcode.com/problems/contains-duplicate-ii/) (Easy)

Given an array of integers and an integer *k*, find out whether there are two distinct indices *i* and *j* in the array such that **nums[i] = nums[j]** and the **absolute** difference between *i* and *j* is at most *k*.

**Example 1:**

```
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1
Output: true
```

**Example 3:**

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```



# [219. 存在重复元素 II](https://leetcode-cn.com/problems/contains-duplicate-ii/)

难度简单208

给定一个整数数组和一个整数 *k*，判断数组中是否存在两个不同的索引 *i* 和 *j*，使得 **nums [i] = nums [j]**，并且 *i* 和 *j* 的差的 **绝对值** 至多为 *k*。

 

**示例 1:**

```
输入: nums = [1,2,3,1], k = 3
输出: true
```

**示例 2:**

```
输入: nums = [1,0,1,1], k = 1
输出: true
```

**示例 3:**

```
输入: nums = [1,2,3,1,2,3], k = 2
输出: false
```



# 题目大意

这是⼀道简单题，如果数组⾥⾯有重复数字，并且重复数字的下标差值⼩于等于 `K` 就输出 true，如果没
有重复数字或者下标差值超过了 `K` ，则输出 `false`。  