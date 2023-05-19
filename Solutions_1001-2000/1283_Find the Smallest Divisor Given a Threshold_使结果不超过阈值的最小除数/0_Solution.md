# 1283_Find the Smallest Divisor Given a Threshold_使结果不超过阈值的最小除数

## 解法一：二分

**思路分析**：

$\left \lceil \frac{nums[1]}{x}  \right \rceil +  \left \lceil \frac{nums[2]}{x}  \right \rceil + \cdots + \left \lceil \frac{nums[n]}{x}  \right \rceil \le threshold$

上取整的技巧：

$\left \lceil \frac{a}{b}  \right \rceil = \left \lfloor \frac{a + b - 1}{b}\right \rfloor$

标准二分模板题

**复杂度分析**：

- 时间复杂度：$O(N \log \max(nums))$，其中 $C$ 是一个常数，为二分查找的上下限之差。我们在 $[1, \max{quantities}]$ 里使用二分查找定位除数；

- 空间复杂度：$O(1)$。
