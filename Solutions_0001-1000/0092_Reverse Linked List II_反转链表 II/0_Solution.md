# 92. Reverse Linked List II_反转链表 II (Medium)

![反转链表](https://cdn.acwing.com/media/article/image/2022/03/13/41956_2db596b0a2-solve.png)

## 解法一：反转链表(模拟) $O(n)$

- 第一步，我们先将 `m` 到 `n` 之间的指针翻转（不包含第 `m` 个节点）
- 第二步我们将 `m` 的指针指向 `c`，将 `a` 的指针指向 `n`

此时我们就完成了 `m` 到 `n` 之间的翻转！


**复杂度分析**
- 时间复杂度：整个链表只遍历了一遍，所以时间复杂度是 $O(n)$。

