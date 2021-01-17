# [137. Single Number II](https://leetcode.com/problems/single-number-ii/) (Medium)

Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. *Find the single element and return it*.

 

**Example 1:**

```
Input: nums = [2,2,3,2]
Output: 3
```

**Example 2:**

```
Input: nums = [0,1,0,1,0,1,99]
Output: 99
```

 

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
- Each element in `nums` appears exactly **three times** except for one element which appears **once**.

 

**Follow up:** Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



# [137. 只出现一次的数字 II](https://leetcode-cn.com/problems/single-number-ii/)

难度中等

给定一个**非空**整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

**说明：**

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

**示例 1:**

```
输入: [2,2,3,2]
输出: 3
```

**示例 2:**

```
输入: [0,1,0,1,0,1,99]
输出: 99
```