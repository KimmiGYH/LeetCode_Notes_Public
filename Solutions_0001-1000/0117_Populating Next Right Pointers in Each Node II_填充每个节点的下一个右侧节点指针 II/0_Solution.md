# 117_Populating Next Right Pointers in Each Node II_填充每个节点的下一个右侧节点指针 II

## 解法一：(BFS，树的遍历) $O(n)$

这道题目和 [Populating Next Right Pointers in Each Node](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/) 类似，不同点在于这道题目的输入数据不一定是一棵完美二叉树。

从根节点开始宽度优先遍历，每次遍历一层，从左到右依次遍历每个节点。
遍历时维护下一层节点的链表。对于每个节点，依次判断它的左儿子和右儿子是否在存在，如果存在，则插入下一层链表的末尾。

为了便于理解，我们模拟一下样例的操作流程：

- 第一步，遍历根节点，依次将它的左右儿子插入下一层链表，得到 2->3；
- 第二步，从左到右遍历第二层，即遍历 2->3，依次将它们的子节点插入下一层链表，得到 4->5->7；
- 第三步，遍历到叶节点层，算法结束；

时间复杂度分析：
每个节点仅会遍历一次。对于每个节点，遍历时维护下一层链表的时间复杂度是 $O(1)$，所以总时间复杂度是 $O(n)$。

[reference](https://www.acwing.com/solution/content/206/)