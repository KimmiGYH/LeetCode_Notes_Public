# 530_Minimum Absolute Difference in BST_二叉搜索树的最小绝对差

二叉搜索树，注意有序性，利用中序遍历。

## 解法一：递归

需要用一个 `pre` 节点记录一下 `cur` 节点的前一个节点。
![中序遍历](https://code-thinking-1253855093.file.myqcloud.com/pics/20210204153247458.png)

```cpp
if (pre != NULL){       // 中
    result = min(result, root->val - pre->val);
}
pre = root; // 记录前一个
```

## 解法二：迭代stack

- 考察二叉树的中序遍历
