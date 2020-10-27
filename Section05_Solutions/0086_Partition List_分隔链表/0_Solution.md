# 86. Partition List_分隔链表 (Medium)

(线性扫描) $O(n)$

定义两个头结点 `lh`, `rh`，和尾结点 `lt`, `rt`，分别存储两个部分对应的链表。

然后遍历原链表，对于每个节点，如果小于 `x`，则插入 `lh` 左链表的结尾；否则，插入 `rh` 右链表的结尾。

最后将拼接左右链表。



时间复杂度分析：原链表只遍历一次，所以时间复杂度是 $O(n)$。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0086_Partition%20List_%E5%88%86%E9%9A%94%E9%93%BE%E8%A1%A8/solve.png)