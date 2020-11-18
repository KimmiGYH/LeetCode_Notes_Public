# 236. Lowest Common Ancestor of a Binary Tree_二叉树的最近公共祖先 (Medium)



## 解法一：后续遍历DFS

[二叉树的最近公共祖先（后序遍历 DFS ，清晰图解）](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu/)

**解题思路：**

大家记得看一下他讲解的「最近公共祖先」这个概念，由于需要先知道左右子树的情况，然后决定向上返回什么。因此**「后序遍历」**的思想是很关键。



**祖先的定义：** 若节点 `p` 在节点 `root` 的左（右）子树中，或 `p = root`，则称 `root` 是 `p` 的祖先。

![img](https://pic.leetcode-cn.com/83402bb4c1bba2746effc5607d9654aeb9c3496b4a846d41ce61adb5af02c0f5-Picture1.png)



**最近公共祖先的定义：** 设节点 `root` 为节点 `p`，`q` 的某公共祖先，若其左子节点 `root->left` 和右子节点 `root->right` 都不是 `p`，`q`的公共祖先，则称 `root` 是“最近的公共祖先”。



根据以上定义，若 `root` 是 `p`，`q` 的 **最近公共祖先**，则只可能为以下情况之一：

1. `p` 和 `q` 在 `root` 的子树中，且分列 `root` 的 **异侧** （即分别在左、右子树中）；
2. `p = root`，且 `q` 在 `root` 的左或右子树中；
3. `q = root`，且 `p` 在 `root` 的左或右子树中；



![img](https://pic.leetcode-cn.com/e48705d412500d43fa81c1d8fdd107bb2d0c7dfa12bdc588cd88f481b4b9f7d8-Picture2.png)



考虑通过递归对二叉树进行后序遍历，当遇到节点 `p` 或 `q` 时返回。从底至顶回溯，当节点 `p`、`q` 在节点 `root` 的异侧时，节点 `root` 即为最近公共祖先，则向上返回 `root`。



**递归解析：**

1. **终止条件**

   1. 当越过叶节点 `!left && !right` ，则直接返回 `null`；

   2. 当 `root` 等于 `p`, `q`，则直接返回 `root`；

      

2. **递推工作**

   1. 开启递归左子节点，返回值记为 `left`；

   2. 开启递归右子节点，返回值记为 `right`；

      

3. **返回值**

   1. 当 `left` 和 `right` **同时为空**：说明 `root` 的左/右子树中都不包含 `p`，`q`，返回 `null`；
   2. 当 `left` 和 `right` **同时不为空**：说明 `p`，`q`分别在 `root` 的 **异侧**（分别在 左 / 右子树），因此 `root` 为最近公共祖先，返回 `root`；
   3. 当 `left` **为空**，`right` **不为空**：`p`，`q` 都不在 `root` 的左子树中，直接返回 `right`。具体可分为两种情况：
      1. `p`, `q` 其中一个在 `root` 的 **右子树** 中，此时 `right` 指向 `p` （假设为 `p`）；
      2. `p`, `q` 两节点都在 `root` 的 **右子树** 中，此时 `right` 指向 **最近公共祖先节点**；
   4. 当 `left` **不为空**，`right` **为空**：与情况 `3.` 同理；



##### 复杂度分析

- **时间复杂度** $O(N)$：其中 `N` 为二叉树节点数；最差情况下，需要递归遍历树的所有节点。
- **空间复杂度** $O(N)$：最差情况下，递归深度达到 `N`，系统使用 `O(N)` 大小的额外空间。


![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0236_Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88/solve.png)




## 解法二：用 `|= `



第一位表示有没有 `q`，第二位表示有没有 `p`：

`q`        `p`

0		0		表示 p、q 都没有

0		1		表示有 p 无 q

1		0		表示有 q 无 p

1		1		表示 p、q 都有



- 如果 `root` 为空，则返回 `0`
- 先去递归左子树：
  - 如果 `root` 为 `p`，则 state 的个位赋成 `1`；
  - 如果 `root` 为 `q`，则 state 的十位赋成 `1`然后左移（或者直接赋成 `2`）；
- 然后再去右子树里判断一下：
  - “或” 上右子树遍历的结果 `state |= dfs(root->right, p, q);`
- 如果 state 等于 `3`，则表示当前子树中既有 `p` 又有 `q`；
- 且当 `ans` 没有赋过值的话，说明当前子树是第一个包含 `p` 和 `q` 的子树，当前的根节点就是它们的最近公共祖先
- 返回 state































