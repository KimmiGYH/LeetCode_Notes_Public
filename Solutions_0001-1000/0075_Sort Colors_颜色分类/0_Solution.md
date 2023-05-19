# [75. Sort Colors](https://leetcode.com/problems/sort-colors/) (Medium)

## 解法一：计数排序

计数排序：分别统计0,1,2,的元素个数，然后把它们放回原有的数组。


## 解法二：三路快排

将数组分成三段
- `[0, j-1]`段放`0`
- `[j, k-1]`段放`1`，`i`在这段中
- `[k, n-1]`段放`2`

`ai` 分三种情况讨论：

① `0`：`swap(ai, aj)`, `j++, i++`

② `2`：`swap(ai, ak)`, `k--`

③ `1`:  `i++`

