# 559_Maximum Depth of N-ary Tree_N 叉树的最大深度

## 解法一：BFS

层序遍历求最大深度，万能的做法

## 解法二：DFS

给 N叉树，求最大深度，直接递归做即可。
求每个子结点的最大深度，再加上 $1$。

**时间复杂度**
- 每个结点仅遍历一次，故时间复杂度为 $O(n)$
