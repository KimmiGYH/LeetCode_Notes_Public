# 328. Odd Even Linked List_奇偶链表 (Medium)

(链表) $O(n)$

从前往后遍历整个链表，遍历时维护四个指针：奇数链表头结点，奇数链表尾节点，偶数链表头结点，偶数链表尾节点。

遍历时将位置编号是奇数的节点插在奇数链表尾节点后面，将位置编号是偶数的节点插在偶数链表尾节点后面。

遍历完整个链表后，将偶数链表头结点插在奇数链表尾节点后面即可。

时间复杂度分析：整个链表只遍历一次，所以时间复杂度是 $O(n)$，遍历时只记录了常数个额外的指针，所以额外的空间复杂度是 $O(1)$。



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0328_Odd%20Even%20Linked%20List_%E5%A5%87%E5%81%B6%E9%93%BE%E8%A1%A8/solve.png)