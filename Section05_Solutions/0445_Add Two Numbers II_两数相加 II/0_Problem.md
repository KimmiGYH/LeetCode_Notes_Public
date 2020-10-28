# 445. Add Two Numbers II (Medium)

Medium

You are given two **non-empty** linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Follow up:**
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

**Example:**

```
Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
```



# [445. 两数相加 II](https://leetcode-cn.com/problems/add-two-numbers-ii/)

难度中等293

给你两个 **非空** 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

 

**进阶：**

如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

 

**示例：**

```
输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
```



# 题目大意

这道题是第 2 题的变种题，第 2 题中的 2 个数是从个位逆序排到⾼位，这样相加只⽤从头交到尾，进位
⼀直进位即可。这道题⽬中强制要求不能把链表逆序。 2 个数字是从⾼位排到低位的，这样进位是倒着
来的。  

