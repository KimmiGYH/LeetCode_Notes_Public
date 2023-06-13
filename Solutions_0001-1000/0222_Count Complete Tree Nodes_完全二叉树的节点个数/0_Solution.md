## 解法一：递归DFS

根据完全二叉树的性质简化遍历次数

这是一棵**完全二叉树**：除最后一层外，其余层全部铺满；且最后一层向左停靠。

![examples](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0222_Count%20Complete%20Tree%20Nodes_%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%8A%82%E7%82%B9%E4%B8%AA%E6%95%B0/%E4%BA%8C%E5%8F%89%E6%A0%91.png)

- 如果根节点的左子树深度等于右子树深度，则说明**左子树为满二叉树**

- 如果根节点的左子树深度大于右子树深度，则说明**右子树为满二叉树**

- 如果知道子树是满二叉树，那么就可以轻松得到该子树的节点数目：`(1<<depth) - 1;` // `depth`为子树的深度；为了加快幂的运算速度，可以使用移位操作符
- 接着我们只需要接着对另一子树递归即可
- 时间复杂度为`O(logn * logn)`，空间复杂度为`O(1)`【不考虑递归调用栈】


链接：https://leetcode-cn.com/problems/count-complete-tree-nodes/solution/c-san-chong-fang-fa-jie-jue-wan-quan-er-cha-shu-de/



思路：

- 二叉树一般都可以考虑成递归问题，对于每个节点，计算一直向左和一直向右的高度，

- 如果相等则说明是满二叉树，那么该树节点个数为`2^h−1`(h是二叉树的高度)；`(1<<h) -1;`

- 如果不相等则说明不是满二叉树，则需要递归地向下求解，该棵树的节点个数等于**左子树节点数 + `1` + 右子树节点数**。

其实这和一般的二叉树计算节点个数的思路是一样的，不同点在于这是**完全二叉树**，所以如果一直向左和一直向右的高度相等的话就可以马上计算出节点个数而不用继续向下递归了。

##### 时间复杂度

这道题相当于二分查找最后一层最后一个节点的位置，每次查找的复杂度是`O(logn)`，一共需要查找`O(logn)`次，所以复杂度为 `O(logn∗logn)`。

**示例一：**

[solve_eg1]

------

**示例二：**

[solve_eg2]



## 解法二：二分查找

[参考：Huifeng Guan: 【每日一题】222. Count Complete Tree Nodes](https://youtu.be/JSq15O0Bs-E)

问 `K` 是否是二叉树中的某一个数？ `K/2` 是该节点的父节点，比如：

```cpp
[K, K/2, K/2/2, ..., 1]
[5, 2, 1]
[7, 3, 1]
[6, 3, 1]
```

每层数的范围为 `2^(h-1)` ~ `2^h - 1`，比如 ![example](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg) 中，最后一行 `4 5 6` 是介于 `2^2 ~ 2^3 - 1` 之间的。

然后进行二分查找

[solve_二分查找]