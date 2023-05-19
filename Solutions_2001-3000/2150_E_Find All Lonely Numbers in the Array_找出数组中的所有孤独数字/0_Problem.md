# [2150. Find All Lonely Numbers in the Array](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/) (Medium)

You are given an integer array `nums`. A number `x` is **lonely** when it appears only **once**, and no **adjacent** numbers (i.e. `x + 1` and `x - 1)` appear in the array.

Return ***all** lonely numbers in* `nums`. You may return the answer in **any order**.

 

**Example 1:**

```
Input: nums = [10,6,5,8]
Output: [10,8]
Explanation: 
- 10 is a lonely number since it appears exactly once and 9 and 11 does not appear in nums.
- 8 is a lonely number since it appears exactly once and 7 and 9 does not appear in nums.
- 5 is not a lonely number since 6 appears in nums and vice versa.
Hence, the lonely numbers in nums are [10, 8].
Note that [8, 10] may also be returned.
```

**Example 2:**

```
Input: nums = [1,3,5,3]
Output: [1,5]
Explanation: 
- 1 is a lonely number since it appears exactly once and 0 and 2 does not appear in nums.
- 5 is a lonely number since it appears exactly once and 4 and 6 does not appear in nums.
- 3 is not a lonely number since it appears twice.
Hence, the lonely numbers in nums are [1, 5].
Note that [5, 1] may also be returned.
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^6`



# [2150. 找出数组中的所有孤独数字](https://leetcode-cn.com/problems/find-all-lonely-numbers-in-the-array/)

难度中等

给你一个整数数组 `nums` 。如果数字 `x` 在数组中仅出现 **一次** ，且没有 **相邻** 数字（即，`x + 1` 和 `x - 1`）出现在数组中，则认为数字 `x` 是 **孤独数字** 。

返回 `nums` 中的 **所有** 孤独数字。你可以按 **任何顺序** 返回答案。

 

**示例 1：**

```
输入：nums = [10,6,5,8]
输出：[10,8]
解释：
- 10 是一个孤独数字，因为它只出现一次，并且 9 和 11 没有在 nums 中出现。
- 8 是一个孤独数字，因为它只出现一次，并且 7 和 9 没有在 nums 中出现。
- 5 不是一个孤独数字，因为 6 出现在 nums 中，反之亦然。
因此，nums 中的孤独数字是 [10, 8] 。
注意，也可以返回 [8, 10] 。
```

**示例 2：**

```
输入：nums = [1,3,5,3]
输出：[1,5]
解释：
- 1 是一个孤独数字，因为它只出现一次，并且 0 和 2 没有在 nums 中出现。
- 5 是一个孤独数字，因为它只出现一次，并且 4 和 6 没有在 nums 中出现。
- 3 不是一个孤独数字，因为它出现两次。
因此，nums 中的孤独数字是 [1, 5] 。
注意，也可以返回 [5, 1] 。
```

 

**提示：**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^6`

