# 700_Search in a Binary Search Tree_二叉搜索树中的搜索

## 解法一：递归

**二叉搜索树**是一个有序树：

- 若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
- 若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
- 它的左、右子树也分别为二叉搜索树

这就决定了，二叉搜索树，递归遍历和迭代遍历和普通二叉树都不一样。

## 解法二：迭代

一提到二叉树遍历的迭代法，可能立刻想起使用栈来模拟深度遍历，使用队列来模拟广度遍历。

对于二叉搜索树可就不一样了，因为二叉搜索树的特殊性，也就是节点的有序性，可以不使用辅助栈或者队列就可以写出迭代法。

对于一般二叉树，递归过程中还有回溯的过程，例如走一个左方向的分支走到头了，那么要调头，在走右分支。

而**对于二叉搜索树，不需要回溯的过程，因为节点的有序性就帮我们确定了搜索的方向。**

例如要搜索元素为3的节点，**我们不需要搜索其他节点，也不需要做回溯，查找的路径已经规划好了。**

中间节点如果大于 $3$ 就向左走，如果小于 $3$ 就向右走，如图：
![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20200812190213280.png)

## 总结

本篇我们介绍了二叉搜索树的遍历方式，因为二叉搜索树的**有序性**，遍历的时候要比普通二叉树简单很多。