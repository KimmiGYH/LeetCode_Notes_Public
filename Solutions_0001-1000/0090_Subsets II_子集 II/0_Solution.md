# 90. Subsets II_子集 II (Medium)

[Sheep LeetCode 90. Subsets II 中文](https://youtu.be/mJb7LESm3A8) 已经消失了

## 解法一：Enumerate numbers for a position

**同一深度不能有重复的数：**

`i > startIndex` 表示对于当前这层递归循环只能使用其中一个元素，另一个重复元素可以在下层循环使用。

```c++
if (i > startIndex && nums[i] == nums[i - 1])
    continue;
```

类似于 ![第40题的分析](https://code-thinking-1253855093.file.myqcloud.com/pics/20230310000918.png)

[第90题的分析]：
![第90题的分析](https://code-thinking-1253855093.file.myqcloud.com/pics/20201124195411977.png)
## 解法二：找出重复出现的个数

为了方便处理，我们先将数组排序，这样相同元素就会排在一起。

然后暴力搜索所有方案，搜索顺序是这样的：

- 我们先枚举每个不同的数，枚举到数 `x` 时，我们求出 `x` 的个数 `k`，然后我们枚举在集合中放入 `0,1,2,…k` 个 `x`，共 `k+1` 种情况。
- 当枚举完最后一个数时，表示我们已经选定了一个集合，将该集合加入答案中即可。

##### 时间复杂度分析

- 不同子集的个数最多有 $2^n$ 个，另外存储答案时还需要 $O(n)$ 的计算量，所以时间复杂度是 $O(n * 2^n)$。



