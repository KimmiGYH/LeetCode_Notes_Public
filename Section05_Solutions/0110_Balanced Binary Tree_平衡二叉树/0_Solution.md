# 110. Balanced Binary Tree_平衡二叉树



**(递归) `O(n)`**

递归判断：

先递归判断两棵子树是否是平衡的，递归的过程中记录每棵树的最大深度值，然后判断两棵子树的最大深度的差是否不大于1。

##### 时间复杂度分析

每个节点仅被遍历一次，且判断的复杂度是 `O(1)`。所以总时间复杂度是 `O(n)`。



[basketwangCoding: [Leetcode 110] Balanced Binary Tree](https://youtu.be/Be5CUodZliM)


![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0110_Balanced%20Binary%20Tree_%E5%B9%B3%E8%A1%A1%E4%BA%8C%E5%8F%89%E6%A0%91/solve.png)