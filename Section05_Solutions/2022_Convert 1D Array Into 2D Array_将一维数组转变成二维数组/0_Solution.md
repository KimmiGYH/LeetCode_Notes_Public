# 2022_Convert 1D Array Into 2D Array_将一维数组转变成二维数组

- 如果 $original.size() != m*n$ 则无法构成二维数组，此时返回空数组。
- 否则我们可以遍历 $original$，每 $n$ 个元素创建一个一维数组，放入二维数组中。
- 或者写成 `res[i][j] = original[idx++];` idx++ 指针自增

**复杂度分析**

- 时间复杂度：$O(mn)$。
- 空间复杂度：$O(mn)$。
