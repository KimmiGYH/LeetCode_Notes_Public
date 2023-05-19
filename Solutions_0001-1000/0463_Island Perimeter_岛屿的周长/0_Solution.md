# 463. Island Perimeter_岛屿的周长 (Easy)

## 思路

岛屿问题最容易让人想到BFS或者DFS，但是这道题还真的没有必要。

## 解法一：

- 使用方向数组。
- 如何统计边界？从某个陆地格子出发：
  - 1) 出界时说明是边界
  - 2) 从陆地格子 `grid[i][j] == 1` 移动到隔壁的水域格子 `grid[x][y] == 0` 时，说明是边界

**复杂度分析**
- 时间复杂度：$O(m*n)$，其中 $m$ 为网格的高度，$n$ 为网格的宽度。我们需要遍历每个格子，每个格子要看其周围 $4$ 个格子是否为岛屿，因此总时间复杂度为 $O(4mn)=O(mn)$。
- 空间复杂度：$O(1)$。只需要常数空间存放若干变量。


## 解法二：

[Carl的题解](https://leetcode-cn.com/problems/island-perimeter/solution/463-dao-yu-de-zhou-chang-mo-ni-bian-ke-by-carlsun-/)

计算出总的岛屿数量，因为有一对相邻两个陆地，边的总数就减 `2`，那么在计算出相邻岛屿的数量就可以了。

```c++
result = 岛屿数量 * 4 - conn * 2;
```

![solve_2](https://pic.leetcode-cn.com/1604023233-VZQcqq-463.%E5%B2%9B%E5%B1%BF%E7%9A%84%E5%91%A8%E9%95%BF1.png)