# 101. Symmetric Tree_对称二叉树 (Easy)



## 解法一：递归DFS

**(递归) $O(n)$**

- 如果 `root` 是空的，可以默认是左右对称的空树
- 否则递归地去看下当前节点左右两棵子树是否左右对称
- DFS一下：
  - 如果左右子树都为空，则对称
  - 如果其中某一棵树是空的，或者两个节点的值不一样，则说明它们不是左右对称的
  - 否则说明这两棵子树的根节点一样，只需要递归地看下`p->left`和`q->right`是否左右对称、`p->right`和`q->left`是否左右对称

##### 时间复杂度分析

从上到下每个节点仅被遍历一遍，所以时间复杂度是 `O(n)`。





