# [617. Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/description/) (Easy)



You are given two binary trees `root1` and `root2`.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return *the merged tree*.

**Note:** The merging process must start from the root nodes of both trees.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/05/merge.jpg)

```
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
```

**Example 2:**

```
Input: root1 = [1], root2 = [1,2]
Output: [2,2]
```

 

**Constraints:**

- The number of nodes in both trees is in the range `[0, 2000]`.
- `-10^4 <= Node.val <= 10^4`



# [617. 合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/description/) (简单)



给你两棵二叉树： `root1` 和 `root2` 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，**不为** null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

**注意:** 合并过程必须从两个树的根节点开始。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/02/05/merge.jpg)

```
输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
输出：[3,4,5,5,4,null,7]
```

**示例 2：**

```
输入：root1 = [1], root2 = [1,2]
输出：[2,2]
```

 

**提示：**

- 两棵树中的节点数目在范围 `[0, 2000]` 内
- `-10^4 <= Node.val <= 10^4`