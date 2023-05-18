# 25. Reverse Nodes in k-Group_K 个一组翻转链表 (Hard)

[【反转链表【基础算法精讲 06】】 【精准空降到 05:06】 ](https://www.bilibili.com/video/BV1sd4y1x7KN/?share_source=copy_web&vd_source=672840fcf5c68492bb4e1f49d5c87506&t=306)

- 先遍历一下 `p` 后面够不够 `k` 个元素，如果遍历完 `q` 为空的话，那么 `break`；
- 之后处理内部的边
- 最后两边处理一下

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0025_Reverse%20Nodes%20in%20k-Group_K%20%E4%B8%AA%E4%B8%80%E7%BB%84%E7%BF%BB%E8%BD%AC%E9%93%BE%E8%A1%A8/solve.png)