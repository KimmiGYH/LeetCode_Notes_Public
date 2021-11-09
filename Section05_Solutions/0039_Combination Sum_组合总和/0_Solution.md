# 39. Combination Sum_组合总和



[Leetcode 39(medium). Combination Sum【前女友/DFS/Recursion/Backtracking】中文](https://youtu.be/OiImuUKQDng)

[花花酱 LeetCode 39. Combination Sum ](https://youtu.be/zIY2BWdsbFs)


## 写法一：(faster than 98.26% )

排序，然后在 for 循环内就设置终止条件：

```c++
if (candidates[i] > target) break;
```

在原味版的基础上，注意 `dfs` 中的 index `i` 不需要写成 `i+1`，因为数字是可以重复使用的。

![原味版](https://github.com/KimmiGYH/LeetCode_Notes_Public/blob/master/Section05_Solutions/0039_Combination%20Sum_%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C/%E5%8E%9F%E5%91%B3%E7%89%88.png?raw=true)


![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0039_Combination%20Sum_%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C/solve.png)