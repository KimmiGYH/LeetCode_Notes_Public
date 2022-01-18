# [220. Contains Duplicate III](https://leetcode.com/problems/contains-duplicate-iii/)] (Medium)

Given an array of integers, find out whether there are two distinct indices *i* and *j* in the array such that the **absolute** difference between **nums[i]** and **nums[j]** is at most *t* and the **absolute** difference between *i* and *j* is at most *k*.

 

**Example 1:**

```
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
```

**Example 3:**

```
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
```

 

**Constraints:**

- `0 <= nums.length <= 2 * 104`
- `-231 <= nums[i] <= 231 - 1`
- `0 <= k <= 104`
- `0 <= t <= 231 - 1`



# [220. 存在重复元素 III](https://leetcode-cn.com/problems/contains-duplicate-iii/)

难度中等

在整数数组 `nums` 中，是否存在两个下标 ***i\*** 和 ***j\***，使得 **nums [i]** 和 **nums [j]** 的差的绝对值小于等于 ***t*** ，且满足 ***i\*** 和 ***j\*** 的差的绝对值也小于等于 ***k*** 。

如果存在则返回 `true`，不存在返回 `false`。

 

**示例 1:**

```
输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
```

**示例 2:**

```
输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
```

**示例 3:**

```
输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false
```



# 题目大意

给出⼀个数组 `num`，再给 K 和 `t`。问在 `num` 中能否找到⼀组 `i` 和 j，使得 `num[i]` 和 `num[j]` 的绝对差值最⼤为 `t`，并且 `i` 和 `j` 之前的绝对差值最⼤为 `k`。  

