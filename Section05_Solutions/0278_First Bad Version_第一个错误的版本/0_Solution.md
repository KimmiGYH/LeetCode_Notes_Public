# 278_First Bad Version_第一个错误的版本 (Easy)

## 解法一：(二分) $O(logn)$

- 整个序列可以分为两段，前半段都是成功的版本，后半段都是失败的版本。所以该问题具有二分性质，直接二分即可。
- 答案在左边，所以 $r = mid$

**时间复杂度分析**：

- 二分检索只会调用 $logn$ 次API，所以时间复杂度是 $O(logn)$。
