# [33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) (Medium)

You are given an integer array `nums` sorted in ascending order (with **distinct** values), and an integer `target`.

Suppose that `nums` is rotated at some pivot unknown to you beforehand (i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

*If `target` is found in the array return its index, otherwise, return `-1`.*

 

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

**Example 3:**

```
Input: nums = [1], target = 0
Output: -1
```

 

**Constraints:**

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All values of `nums` are **unique**.
- `nums` is guaranteed to be rotated at some pivot.
- `-10^4 <= target <= 10^4`



# [33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

难度中等

升序排列的整数数组 `nums` 在预先未知的某个点上进行了旋转（例如， `[0,1,2,4,5,6,7]` 经旋转后可能变为 `[4,5,6,7,0,1,2]` ）。

请你在数组中搜索 `target` ，如果数组中存在这个目标值，则返回它的索引，否则返回 `-1` 。

 

**示例 1：**

```
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```

**示例 2：**

```
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
```

**示例 3：**

```
输入：nums = [1], target = 0
输出：-1
```

 

**提示：**

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- `nums` 中的每个值都 **独一无二**
- `nums` 肯定会在某个点上旋转
- `-10^4 <= target <= 10^4`