# 111. Minimum Depth of Binary Tree_二叉树的最小深度



(递归) $O(n)$

对于每个节点：

- 如果是空节点，返回 `0`；
- 如果没有子节点，说明是叶节点，则返回 `1`；
- 如果有子节点，说明是内部结点，则返回子节点的深度的最小值 `+ 1`（加上根节点这层）；



**时间复杂度分析**

- 每个节点仅被遍历一次，且遍历时所有操作的复杂度是 `O(1)`，所以总时间复杂度是 `O(n)`。



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0111_Minimum%20Depth%20of%20Binary%20Tree_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E5%B0%8F%E6%B7%B1%E5%BA%A6/solve.png)