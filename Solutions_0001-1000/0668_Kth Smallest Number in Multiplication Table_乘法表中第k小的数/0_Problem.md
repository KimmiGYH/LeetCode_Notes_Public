# 668. Kth Smallest Number in Multiplication Table (Hard)

Nearly everyone has used the [Multiplication Table](https://en.wikipedia.org/wiki/Multiplication_table). The multiplication table of size `m x n` is an integer matrix `mat` where `mat[i][j] == i * j` (**1-indexed**).

Given three integers `m`, `n`, and `k`, return *the* `k^th` *smallest element in the* `m x n` *multiplication table*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/05/02/multtable1-grid.jpg)

```
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/05/02/multtable2-grid.jpg)

```
Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.
```

 

**Constraints:**

- `1 <= m, n <= 3 * 10^4`
- `1 <= k <= m * n`



# [668. 乘法表中第k小的数](https://leetcode-cn.com/problems/kth-smallest-number-in-multiplication-table/)

难度困难

几乎每一个人都用 [乘法表](https://baike.baidu.com/item/乘法表)。但是你能在乘法表中快速找到第`k`小的数字吗？

给定高度`m` 、宽度`n` 的一张 `m * n`的乘法表，以及正整数`k`，你需要返回表中第`k` 小的数字。

**例 1：**

```
输入: m = 3, n = 3, k = 5
输出: 3
解释: 
乘法表:
1	2	3
2	4	6
3	6	9

第5小的数字是 3 (1, 2, 2, 3, 3).
```

**例 2：**

```
输入: m = 2, n = 3, k = 6
输出: 6
解释: 
乘法表:
1	2	3
2	4	6

第6小的数字是 6 (1, 2, 2, 3, 4, 6).
```

**注意：**

1. `m` 和 `n` 的范围在 [1, 30000] 之间。
2. `k` 的范围在 [1, m * n] 之间。

