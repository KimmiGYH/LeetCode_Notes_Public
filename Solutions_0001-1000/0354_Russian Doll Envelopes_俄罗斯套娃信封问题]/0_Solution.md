# 354_Russian Doll Envelopes_俄罗斯套娃信封问题 (Hard)

[最长上升子序列模板](https://www.acwing.com/file_system/file/content/whole/index/content/1624417/)

## 解法一：动态规划 - 最长上升子序列

1. 按照第一维宽度从小到大排序。

2. 状态表示：设状态 $f(i)$ 表示以第 $i$ 个信封为结尾的最长上升子序列的长度。

3. 状态转移：假设我们能快速找到一个 $j < i$，满足 `e[j][0] < e[i][0]` 并且 `e[j][1] < e[i][1]`，则转移 $f(i) = max(f(j) + 1)$。
