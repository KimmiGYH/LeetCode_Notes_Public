# 206. Reverse Linked List_反转链表



## 解法一：迭代

(链表操作，迭代) `O(n)`
翻转即将所有节点的 `next` 指针指向前驱节点。
由于是单链表，我们在迭代时不能直接找到前驱节点，所以我们需要一个额外的指针保存前驱节点。同时在改变当前节点的 `next` 指针前，不要忘记保存它的后继节点。

空间复杂度分析：遍历时只有3个额外变量，所以额外的空间复杂度是 `O(1)`。
时间复杂度分析：只遍历一次链表，时间复杂度是 `O(n)`。

![solve1](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0206_Reverse%20Linked%20List_%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8/solve1_%E8%BF%AD%E4%BB%A3_v2.png)

## 解法二：递归

(链表操作，递归) `O(n)`
首先我们先考虑 `reverseList` 函数能做什么，它可以翻转一个链表，并返回新链表的头节点，也就是原链表的尾节点。
所以我们可以先递归处理 `reverseList(head->next)`，这样我们可以将以 `head->next` 为头节点的链表翻转，并得到原链表的尾节点`tail`，此时 `head->next` 是新链表的尾节点，我们令它的 `next` 指针指向 `head`，并将 `head->next` 指向空即可将整个链表翻转，且新链表的头节点是 `tail`。

空间复杂度分析：总共递归 `n` 层，系统栈的空间复杂度是 `O(n)`，所以总共需要额外 `O(n)` 的空间。
时间复杂度分析：链表中每个节点只被遍历一次，所以时间复杂度是 `O(n)`。

![solve2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0206_Reverse%20Linked%20List_%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8/solve2_%E9%80%92%E5%BD%92.png.png)







