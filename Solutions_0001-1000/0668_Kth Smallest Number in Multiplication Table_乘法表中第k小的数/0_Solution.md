# 668_Kth Smallest Number in Multiplication Table_乘法表中第k小的数

## 解法一：二分 $O(m∗log⁡(m∗n))$

1) 在378题的基础上，二分结构：

```cpp
if (cnt >= k) r = mid;
else l = mid + 1;
```

2) 最难的是如何确定 `<= mid` 的个数，详见solve.png
一行一行来：
将 `i` 从 `1...m` 枚举行数，满足：
- x <= mid / i;
- x <= n;
- 取的是较小值，res += min(n, mid/i);

**时间复杂度**
- 判定的时间复杂度为 $O(m)$，二分的时间复杂度为 $O(log⁡(m∗n))$，故总时间复杂度为 $O(m∗log⁡(m∗n))$。