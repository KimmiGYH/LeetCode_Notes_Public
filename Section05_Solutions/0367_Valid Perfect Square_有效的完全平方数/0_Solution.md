# 367_Valid Perfect Square_有效的完全平方数

## 解法一：二分查找 $O(logn)$

- 二分查找这个平方根
- 之后再检查它的平方是不是等于 $num$
- 注意处理溢出的两个部分：
  - $int mid = l + 1ll + r >> 1;$ $1ll$ 表示 $long \ long$ 类型的 $1$
  - $mid*mid <= num$ 改写成 $mid <= num / mid$
