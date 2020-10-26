# 92. Reverse Linked List II_反转链表 II (Medium)

​	

(模拟) O(n)



第一步，我们先将 `m` 到 `n` 之间的指针翻转（不包含第 `m` 个节点）

第二步我们将 `m` 的指针指向 `c`，将 `a` 的指针指向 `n`

此时我们就完成了 `m` 到 `n` 之间的翻转！



时间复杂度分析：整个链表只遍历了一遍，所以时间复杂度是 `O(n)`。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0092_Reverse%20Linked%20List%20II_%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8%20II/solve.png)

