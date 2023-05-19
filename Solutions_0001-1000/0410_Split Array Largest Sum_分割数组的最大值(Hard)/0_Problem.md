# [410. Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) (Hard)

Given an array `nums` which consists of non-negative integers and an integer `m`, you can split the array into `m` non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these `m` subarrays.

 

**Example 1:**

```
Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
```

**Example 2:**

```
Input: nums = [1,2,3,4,5], m = 2
Output: 9
```

**Example 3:**

```
Input: nums = [1,4,4], m = 3
Output: 4
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 106`
- `1 <= m <= min(50, nums.length)`



# [410. 分割数组的最大值](https://leetcode-cn.com/problems/split-array-largest-sum/)

难度困难

给定一个非负整数数组 `nums` 和一个整数 `m` ，你需要将这个数组分成 `m` 个非空的连续子数组。

设计一个算法使得这 `m` 个子数组各自和的最大值最小。

 

**示例 1：**

```
输入：nums = [7,2,5,10,8], m = 2
输出：18
解释：
一共有四种方法将 nums 分割为 2 个子数组。 其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
```

**示例 2：**

```
输入：nums = [1,2,3,4,5], m = 2
输出：9
```

**示例 3：**

```
输入：nums = [1,4,4], m = 3
输出：4
```

 

**提示：**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 106`
- `1 <= m <= min(50, nums.length)`