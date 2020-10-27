# 86. Partition List (Medium)

Given a linked list and a value *x*, partition it such that all nodes less than *x* come before nodes greater than or equal to *x*.

You should preserve the original relative order of the nodes in each of the two partitions.

**Example:**

```
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
```



# [86. 分隔链表](https://leetcode-cn.com/problems/partition-list/)

难度中等274

给定一个链表和一个特定值 *x*，对链表进行分隔，使得所有小于 *x* 的节点都在大于或等于 *x* 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

 

**示例:**

```
输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
```



# 题目大意

给定⼀个数 `x`，⽐ `x` ⼤或等于的数字都要排列在⽐ `x` ⼩的数字后⾯，并且相对位置不能发⽣变化。由于
相对位置不能发⽣变化，所以不能⽤类似冒泡排序的思想。  
