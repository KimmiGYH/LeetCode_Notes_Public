# 129. Sum Root to Leaf Numbers_求根到叶子节点数字之和 (Medium)



**(树的遍历) $O(n)$**

从根节点递归遍历整棵树，遍历时维护从根节点到该节点的路径表示的数，当遍历到叶节点时，将路径表示的数累加到答案中。

##### 时间复杂度分析

每个节点仅被遍历一遍，所以时间复杂度是 $O(n)$。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0129_Sum%20Root%20to%20Leaf%20Numbers_%E6%B1%82%E6%A0%B9%E5%88%B0%E5%8F%B6%E5%AD%90%E8%8A%82%E7%82%B9%E6%95%B0%E5%AD%97%E4%B9%8B%E5%92%8C/solve.png)