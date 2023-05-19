# 417. Pacific Atlantic Water Flow_太平洋大西洋水流问题 (Medium)



思路：优化的方法跟之前 [LeetCode 130. Surrounded Regions](https://github.com/KimmiGYH/LeetCode_Notes_Public/tree/master/Section05_Solutions/0130_Surrounded%20Regions_%E8%A2%AB%E5%9B%B4%E7%BB%95%E7%9A%84%E5%8C%BA%E5%9F%9F) 很类似，都是换一个方向考虑问题，既然从每个点向中间扩散会 `TLE`，那么我们就把所有**边缘点**当作起点开始遍历搜索，然后标记能到达的点为 `true`，分别标记出 `Pacific` 和 `Atlantic` 能到达的点，那么最终能返回的点就是二者均为 `true` 的点。我们可以先用`DFS`来遍历二维数组。

## 解法一：DFS `$O(mn)$`



```c++
用了一点位运算，用 int 型的最低两位来表示到太平洋和大西洋
01 表示到太平洋  用 1 表示
10 表示到大西洋  用 2 表示
11 表示到两大洋  用 3 表示
```



时间复杂度：$O(mn)$



## 解法二：BFS