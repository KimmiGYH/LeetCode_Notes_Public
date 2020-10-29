# 82. Remove Duplicates from Sorted List II_删除排序链表中的重复元素 II (Medium)

(线性扫描) $O(n)$

为了方便处理边界情况，我们定义一个虚拟元素 `dummy` 指向链表头节点。
然后从前往后扫描整个链表，每次扫描元素相同的一段，如果这段中的元素个数多于`1`个，则将整段元素直接删除。

时间复杂度分析：整个链表只扫描一遍，所以时间复杂度是 $O(n)$。



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0082_Remove%20Duplicates%20from%20Sorted%20List%20II_%E5%88%A0%E9%99%A4%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8%E4%B8%AD%E7%9A%84%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0%20II/solve.png)