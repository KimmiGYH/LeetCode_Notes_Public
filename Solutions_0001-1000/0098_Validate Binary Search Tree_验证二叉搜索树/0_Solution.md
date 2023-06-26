# 98. Validate Binary Search Tree_验证二叉搜索树 (Medium)

## 解法一：递归

递归三步曲：

- 确定递归函数，返回值以及参数
要定义一个 `long long` 的全局变量，用来比较遍历的节点是否有序，因为后台测试数据中有 `int` 最小值，所以定义为 `long long` 的类型，初始化为 `long long` 最小值 `LONG_MIN`。
```cpp
long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
bool isValidBST(TreeNode* root)
```

- 确定终止条件
如果是空节点 是不是二叉搜索树呢？ 是的，二叉搜索树也可以为空！
```cpp
if (root == NULL) return true;
```

- 确定单层递归的逻辑
中序遍历，一直更新 `maxVal`，一旦发现 `maxVal >= root->val`，就返回 `false`，注意元素相同时候也要返回 `false`。
```cpp
bool left = isValidBST(root->left);         // 左

// 中序遍历，验证遍历的元素是不是从小到大
if (maxVal < root->val)
    maxVal = root->val; // 中
else return false;

bool right = isValidBST(root->right);       // 右
return left && right;
```

<!-- --------------------- -->

## 解法二：双指针优化

如果测试数据中有 longlong的最小值，怎么办？

不可能在初始化一个更小的值了吧。 建议避免 初始化最小值，如下方法取到最左面节点的数值来比较。

```cpp
class Solution {
public:
    TreeNode* pre = NULL; // 用来记录前一个节点
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);

        if (pre != NULL && pre->val >= root->val) return false;
        pre = root; // 记录前一个节点

        bool right = isValidBST(root->right);
        return left && right;
    }
};
```

## 解法三：判断中序遍历是否是有序的

从上到下判断，在往下遍历子树的过程中，根据父节点的信息记录并更新子树的值的大小范围

1. 如果当前结点超过了当前的大小范围，则返回 `false`

2. 否则递归遍历左子树，将左子树的最大值的范围更新为当前结点的值；递归遍历右子树，将右子树的最小值的范围更新为当前结点的值。

##### 时间复杂度分析

$O(N)$，每个结点只遍历一次