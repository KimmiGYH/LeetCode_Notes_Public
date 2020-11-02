# 145. Binary Tree Postorder Traversal_二叉树的后序遍历 (Medium)



## 解法一：将前序遍历镜像翻转→后序遍历



- **前序遍历：**`根` → `左` → `右`

- **后序遍历：**`左` → `右` → `根`

观察，将后序遍历翻转`reverse`一下，则是：

- **后序翻转：**`根` → `右` → `左`



近一步思考：

- **前序遍历：**`根` → `左` → `右`

- **后序翻转：**`根` → `右` → `左`



**思路：**要后序遍历，只需将前序遍历的的 `left` 和 `right` 互换得到后序翻转，然后再 `reverse` 一下即可得到后序遍历。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section02_Templates/%E4%BA%8C%E5%8F%89%E6%A0%91/%E4%BA%8C%E5%8F%89%E6%A0%91%E5%89%8D%E5%BA%8F%2B%E4%B8%AD%E5%BA%8F%2B%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86.png)