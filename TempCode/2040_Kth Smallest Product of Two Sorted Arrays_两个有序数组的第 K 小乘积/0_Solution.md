# 040_Kth Smallest Product of Two Sorted Arrays_两个有序数组的第 K 小乘积

## 解法一：二分

我们令 $cnt = count(mid)$ 来计算乘积有多少对 $nums1[i] * nums2[j] \le mid$。

如果这个数目 $< k$，那么说明 $mid$ 肯定不是答案，$k$ 太小，所以应该尝试更大的数（即 $l = m + 1$）。

如果 $cnt \ge k$，说明 $mid$ 可能是答案（因为允许有若干对成绩都等于 $mid$）或者 $mid$ 可能猜大了，所以接下来尝试更小的数（即 $r = mid$）。

利用二分搜值的模板，直至收敛到 $left==right$，就是最终的解。

如何实现函数 $count(mid)$ 呢？

### 方法一：二分

[【每日一题】LeetCode 2040. Kth Smallest Product of Two Sorted Arrays](https://youtu.be/Ct-seYTr1dM?t=886)

最简单的方法就是遍历 $nums1[i]$，在有序数组 $nums2$ 里面用二分法找一个临界位置 $j$，使得 $nums1[i]*nums2[j] \le mid$。 这个临界位置 $j$ 的确定需要分类讨论。

```cpp
nums1[i] * nums2[j] <= m

1. if nums1[i] > 0
    nums2[j] <= floor(mid*1.0 / nums1[i])   [0, j)
    cnt += j

2. if nums1[i] < 0
    nums2[j] >= ceil(mid*1.0 / nums1[i])    [j, n-1]

3. if nums1[i] == 0
    if (mid < 0) cnt += 0
    else cnt += nums2.size()
```

如果 $a > 0$，则不等式 $ab \le x$ 成立的条件是 ${b \le \left\lfloor \frac{x}{a} \right\rfloor}$（向下取整）；

如果 $a < 0$，则不等式 $ab \le x$ 成立的条件是 ${b \ge \left\lceil \frac{x}{a} \right\rceil}$（向上取整）；

- 如果 $nums1[i] > 0$，那么我们有 $nums[j] \le \frac{mid}{nums1[i]}$，当 $\frac{mid}{nums1[i]}$ 不能整除时，我们必须保守地取 $floor()$。这样我们可以用 `upper_bound` 求得第一个大于 $\frac{mid}{nums1[i]}$ 的位置 $j$，那么 $[0, j-1]$ 都是满足条件的解。

- 如果 $nums1[i] < 0$，那么根据不等式性质，移项需要变号，所以我们有 $nums[j] \ge \frac{mid}{nums1[i]}$，当 $\frac{mid}{nums1[i]}$ 不能整除时，我们必须保守地取 $ceil()$. 这样我们可以用 `lower_bound` 求得第一个大于等于 $\frac{mid}{nums1[i]}$ 的位置 $j$，那么 $[j, n-1]$ 都是满足条件的解。

- 特殊地 $nums1[i]==0$，那么有多少j满足 $0*nums[j]\le mid$ 呢？这个其实取决于 $mid$。如果 $mid$ 是负数，无解。如果 $mid$ 是非负数，所有的 $nums2$ 都是解。


## 解法二：双指针


