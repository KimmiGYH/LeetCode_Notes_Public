# 110. Balanced Binary Tree_平衡二叉树

**(递归) `O(n)`**

递归判断：

先递归判断两棵子树是否是平衡的，递归的过程中记录每棵树的最大深度值，然后判断两棵子树的最大深度的差是否不大于1。

##### 时间复杂度分析

每个节点仅被遍历一次，且判断的复杂度是 `O(1)`。所以总时间复杂度是 `O(n)`。



[basketwangCoding: [Leetcode 110] Balanced Binary Tree](https://youtu.be/Be5CUodZliM)


## 解法一：DFS

Leetcode中强调的深度和高度很明显是按照节点来计算的，如图：
![平衡二叉树](https://code-thinking-1253855093.file.myqcloud.com/pics/20210203155515650.png)

**因为求深度可以从上到下去查 所以需要前序遍历（中左右），而高度只能从下到上去查，所以只能后序遍历（左右中）**

