# [81. Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) (Medium)

You are given an integer array `nums` sorted in ascending order (not necessarily **distinct** values), and an integer `target`.

Suppose that `nums` is rotated at some pivot unknown to you beforehand (i.e., `[0,1,2,4,4,4,5,6,6,7]` might become `[4,5,6,6,7,0,1,2,4,4]`).

*If `target` is found in the array return its index, otherwise, return `-1`.*

 

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

 

**Constraints:**

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is guaranteed to be rotated at some pivot.
- `-10^4 <= target <= 10^4`

 

**Follow up:** This problem is the same as [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/), where `nums` may contain **duplicates**. Would this affect the run-time complexity? How and why?



# [81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)

难度中等

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 `[0,0,1,2,2,5,6]` 可能变为 `[2,5,6,0,0,1,2]` )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 `true`，否则返回 `false`。

**示例 1:**

```
输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
```

**示例 2:**

```
输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
```

**进阶:**

- 这是 [搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/) 的延伸题目，本题中的 `nums` 可能包含重复元素。
- 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？



