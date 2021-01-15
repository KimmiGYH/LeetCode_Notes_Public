# 1658_Minimum Operations to Reduce X to Zero_将 x 减到 0 的最小操作数 (Medium)

(贪心 + 前缀和 + 哈希 + 双指针)

- 哈希记录前缀和 `prefix` 及其长度 `len`
- 遍历后缀和 `suffixsum`，在前缀和中查找 `target = x - suffixsum`

**时间复杂度：**

- 每个位置遍历常数次，故总时间复杂度为 $O(n)$。

**空间复杂度：**

- 仅需要常数的额外空间。
