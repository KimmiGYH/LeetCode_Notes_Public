# 23. Merge k Sorted Lists_合并K个排序链表 (Hard)

`归并排序` + `链表`



## 解法一：优先队列

- 每次取出链表头节点进入优先队列

- 弹出堆顶元素，连到新链表尾端
  
- 看k条链表中值最小的头节点是否有后驱节点，有点话把后驱节点插到堆里

##### 时间复杂度

`O(NlogK)` N是节点总数， k是链表总数每次添加和删除操作都是logk的复杂度



## 解法二：分治

[花花酱 LeetCode 23. Merge k Sorted Lists - 刷题找工作 EP252](https://youtu.be/XqA8bBoEdIY)

分治，先将 `K` 个链表分成两个部分，先合并两个部分，再合并这两个部分返回的链表。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0023_Merge%20k%20Sorted%20Lists_%E5%90%88%E5%B9%B6K%E4%B8%AA%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8(Hard)/solve.png)

