# 53_Maximum Subarray_最大子序和 (Easy)

## 解法一：动态规划 $O(n)$

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0053_Maximum%20Subarray_%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C/solve1.png)

- 状态表示：$f(i)$ 表示所有以 $nums[i]$ 结尾的区间中的最大和是多少。

- 递推关系：$f(i) = max(nums[i], f(i-1) + nums[i]) = nums[i] + max(0, f(i-1))$。

  - 用变量 `last` 来记录 $f(i-1)$，得 $f(i) = nums[i] + max(0, last)$，就可以算出来 $f(i)$。之后再把 `last` (即 $f(i-1)$) 更新成 $f(i)$。

**时间复杂度：**

- 状态数为 $O(n)$，转移时间为 $O(1)$，故总时间复杂度为 $O(n)$。

**空间复杂度：**

- 需要额外 $O(n)$ 的空间存储状态。
- 可以通过一个变量 `last` 来替代数组**将空间复杂度优化到常数**。

## 解法二：分治 - 线段树

线段树的解法先放一放，可以参考提高课 245 题。但代码太长，还没学。
