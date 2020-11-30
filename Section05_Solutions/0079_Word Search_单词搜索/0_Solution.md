# 79. Word Search_单词搜索 (Medium)



## 解法一：回溯 + 方向数组



##### (DFS) $O(n^2 3^k)$

在深度优先搜索中，最重要的就是考虑好搜索顺序。

我们先枚举单词的起点，然后依次枚举单词的每个字母。
过程中需要将已经使用过的字母改成一个特殊字母，以避免重复使用字符。

##### 时间复杂度分析

单词起点一共有 $n^2$ 个，单词的每个字母一共有**上下左右**四个方向可以选择，但由于不能走回头路，所以除了单词首字母外，仅有三种选择。所以总时间复杂度是 $O(n^2 3^k)$。


![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0079_Word%20Search_%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2/solve.png)



## 方向数组

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0079_Word%20Search_%E5%8D%95%E8%AF%8D%E6%90%9C%E7%B4%A2/%E6%96%B9%E5%90%91%E6%95%B0%E7%BB%84.png)