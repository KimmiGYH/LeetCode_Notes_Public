# 2. Add Two Numbers_两数相加 (Medium)



(模拟人工加法) $O(n)$

这是道模拟题，模拟我们小时候列竖式做加法的过程：

- 从最低位至最高位，逐位相加，如果和大于等于`10`，则保留个位数字，同时向前一位进`1`.

- 如果最高位有进位，则需在最前面补`1`.

做有关链表的题目，有个常用技巧：添加一个虚拟头结点：

`ListNode *head = new ListNode(-1);`，可以简化边界情况的判断。

时间复杂度：由于总共扫描一遍，所以时间复杂度是 $O(n)$.



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0002_Add%20Two%20Numbers_%E4%B8%A4%E6%95%B0%E7%9B%B8%E5%8A%A0/solve.png)