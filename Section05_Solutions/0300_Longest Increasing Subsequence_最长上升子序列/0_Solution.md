# 300. Longest Increasing Subsequence_最长上升子序列



## 解法一：动态规划



（动态规划）$O(n^2)$

用数组 `dp[i]` 记录以 `nums[i]` 结尾（即 `nums[i]` 为最后一个数字）的最长递增子序列的长度，则递推方程为`dp[i] = max(dp[j]+1)`，其中要求 `1 ≤ j < i` 且 `nums[j] < nums[i]`。

##### 复杂度分析

时间复杂度：$O(n^2)$

 其中 `n` 为数组 `nums` 的长度。动态规划的状态数为 `n`，计算状态 `dp[i]` 时，需要 `O(n)` 的时间遍历 `dp[0…i−1]` 的所有状态，所以总时间复杂度为 $O(n^2)$。

空间复杂度：$O(n)$

需要额外使用长度为 `n` 的 `dp` 数组。



![solve_1](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0300_Longest%20Increasing%20Subsequence_%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97/solve_1.png)




## 解法二：二分搜索



##### 复杂度分析

时间复杂度：$O(nlogn)$

数组 `nums` 的长度为 `n`，我们依次用数组中的元素去更新 `vec` 数组，而更新 `vec` 数组时需要进行 $O(logn)$ 的二分搜索，所以总时间复杂度为 $O(nlogn)$。

空间复杂度：$O(n)$

需要额外使用长度为 `n` 的 `vec` 数组。


![solve_2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0300_Longest%20Increasing%20Subsequence_%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97/solve_2.png)
