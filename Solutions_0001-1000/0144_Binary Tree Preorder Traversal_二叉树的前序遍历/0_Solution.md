# 144. Binary Tree Preorder Traversal_二叉树的前序遍历 (Medium)



## 解法一：递归



## 解法二：迭代

前序遍历的顺序为【根 左 右】
所以我们先从根入手，先把根存储到答案中
然后需要访问左节点，这是就把根指向根的左节点，并压栈
直到左分支被遍历完，这时根和左节点都存储到答案中了，然后可以利用栈中存储的节点进行回溯访问父节点
通过父节点查询右分支，这样进行循环就可以按照【根 左 右】的顺序遍历完整个二叉树

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section02_Templates/%E4%BA%8C%E5%8F%89%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%A0%91%E5%89%8D%E5%BA%8F%2B%E4%B8%AD%E5%BA%8F%2B%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86.png)