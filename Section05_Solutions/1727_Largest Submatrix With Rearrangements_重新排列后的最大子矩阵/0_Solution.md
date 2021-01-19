# 1727_Largest Submatrix With Rearrangements_重新排列后的最大子矩阵（Hard）

## 解法：贪心 + 排序 $O(m * nlogn)$

1. 对矩阵按行将列的值累加，累加时从 `i = 1` 开始，求得 $matrix[i][j] += matrix[i-1][j]$

2. 开个数组 $heights$，将刚刚累加得到的 $matrix[i][j]$ 存进 $heights[j]$ 中，从而求出以 $heights[j]$ 为高度的矩阵面积。

3. 取最大值即可。

**时间复杂度：**

- 确定高度需要 $O(m*n)$，之后排序 $O(m*nlogn)$，所以总共需要 $O(m*nlogn)$