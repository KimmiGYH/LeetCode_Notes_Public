# 83. Remove Duplicates from Sorted List_删除排序链表中的重复元素



(线性扫描) `O(n)`
从前往后扫描整个链表，如果一个节点和其后继节点相同，则直接删除后继节点，否则指针移动到后继节点。

时间复杂度分析：整个链表只扫描一遍，所以时间复杂度是 `O(n)`。



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0083_Remove%20Duplicates%20from%20Sorted%20List_%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0/solve.png)