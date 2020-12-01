# 463. Island Perimeter_岛屿的周长 (Easy)

[Carl的题解](https://leetcode-cn.com/problems/island-perimeter/solution/463-dao-yu-de-zhou-chang-mo-ni-bian-ke-by-carlsun-/)



## 思路

岛屿问题最容易让人想到BFS或者DFS，但是这道题还真的没有必要。



## 解法一：

使用方向数组。

遍历每一个空格，遇到岛屿，计算其上下左右的情况，遇到水域或者出界的情况，就可以计算边了。

![solve_1](https://pic.leetcode-cn.com/1604025390-NccJlv-463.%E5%B2%9B%E5%B1%BF%E7%9A%84%E5%91%A8%E9%95%BF.png)



## 解法二：

计算出总的岛屿数量，因为有一对相邻两个陆地，边的总数就减 `2`，那么在计算出相邻岛屿的数量就可以了。

```c++
result = 岛屿数量 * 4 - conn * 2;
```

![solve_2](https://pic.leetcode-cn.com/1604023233-VZQcqq-463.%E5%B2%9B%E5%B1%BF%E7%9A%84%E5%91%A8%E9%95%BF1.png)