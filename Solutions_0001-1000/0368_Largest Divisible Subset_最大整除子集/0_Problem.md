# [368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/) (Medium)

Given a set of **distinct** positive integers `nums`, return the largest subset `answer` such that every pair `(answer[i], answer[j])` of elements in this subset satisfies:

- `answer[i] % answer[j] == 0`, or
- `answer[j] % answer[i] == 0`

If there are multiple solutions, return any of them.

 

**Example 1:**

```
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```

**Example 2:**

```
Input: nums = [1,2,4,8]
Output: [1,2,4,8]
```

 

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 2 * 10^9`
- All the integers in `nums` are **unique**.



# [368. 最大整除子集](https://leetcode-cn.com/problems/largest-divisible-subset/)

难度中等

给出一个由**无重复的**正整数组成的集合，找出其中最大的整除子集，子集中任意一对 (Si，Sj) 都要满足：Si % Sj = 0 或 Sj % Si = 0。

如果有多个目标子集，返回其中任何一个均可。

 

**示例 1:**

```
输入: [1,2,3]
输出: [1,2] (当然, [1,3] 也正确)
```

**示例 2:**

```
输入: [1,2,4,8]
输出: [1,2,4,8]
```