# 90. Subsets II_子集 II (Medium)



[Sheep LeetCode 90. Subsets II 中文](https://youtu.be/mJb7LESm3A8)



## 解法一：Enumerate numbers for a position





## 解法二：choose or not choose





## 解法三：找出重复出现的个数





为了方便处理，我们先将数组排序，这样相同元素就会排在一起。

然后暴力搜索所有方案，搜索顺序是这样的：

- 我们先枚举每个不同的数，枚举到数 `x` 时，我们求出 `x` 的个数 `k`，然后我们枚举在集合中放入 `0,1,2,…k` 个 `x`，共 `k+1` 种情况。
- 当枚举完最后一个数时，表示我们已经选定了一个集合，将该集合加入答案中即可。



##### 时间复杂度分析

不同子集的个数最多有 $2^n$ 个，另外存储答案时还需要 `O(n)` 的计算量，所以时间复杂度是 $O(n 2^n)$。



