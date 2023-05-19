# 235. Lowest Common Ancestor of a Binary Search Tree_二叉搜索树的最近公共祖先

##### 算法

(暴力) $O(h)$

由于这是一棵二叉查找树，我们可以利用二叉查找树的性质来从根结点开始寻找。

- 首先根结点必定是候选公共祖先，接着如果 `p` 和 `q` 同时出现在左子树，则我们往左儿子移动；如果 `p` 和 `q` 同时出

- 现在右子树，则我们往右儿子移动；

- 若发现不满足 2 中的两个条件，则停止寻找，当前结点就是最近公共祖先。



##### 时间复杂度

- 每次都会降低一层，故最坏时间复杂度也就是树的高度 $O(h)$。


![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0235_Lowest%20Common%20Ancestor%20of%20a%20Binary%20Search%20Tree_%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/solve.png)
