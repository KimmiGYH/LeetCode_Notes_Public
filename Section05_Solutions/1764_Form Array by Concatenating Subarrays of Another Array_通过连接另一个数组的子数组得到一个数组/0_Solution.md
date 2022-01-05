# 1764_Form Array by Concatenating Subarrays of Another Array_通过连接另一个数组的子数组得到一个数组

### 解法一：双指针+模拟题 $O(n * m)$

- 使用 `i` 指针代表 $nums$ 当前枚举到的位置；`j` 代表 $groups$ 中枚举到哪个数组。`cnt` 代表匹配的数组个数。
  - 当 `i` 开头的连续一段和 $groups[j]$ 匹配：`j` 指针右移一位（代表匹配下一个数组），`i` 指针右移 $groups[j].size()$ 长度。
  - 当 `i` 开头的连续一段和 $groups[j]$ 不匹配：`i` 右移一位。

**复杂度分析**
- 时间复杂度：$O(n * m)$
- 空间复杂度：$O(1)$
