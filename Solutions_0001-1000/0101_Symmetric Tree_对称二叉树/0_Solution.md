# 101. Symmetric Tree_对称二叉树 (Easy)



## 解法一：递归DFS

**(递归) $O(n)$**

- 如果 `root` 是空的，可以默认是左右对称的空树
- 否则递归地去看下当前节点左右两棵子树是否左右对称
- DFS一下：
  - 如果左右子树都为空，则对称
  - 如果其中某一棵树是空的，或者两个节点的值不一样，则说明它们不是左右对称的
  - 否则说明这两棵子树的根节点一样，只需要递归地看下`p->left`和`q->right`是否左右对称、`p->right`和`q->left`是否左右对称

具体分解：

```cpp
bool outside = compare(left->left, right->right);   // 左子树：左、 右子树：右
bool inside = compare(left->right, right->left);    // 左子树：右、 右子树：左
bool isSame = outside && inside;                    // 左子树：中、 右子树：中（逻辑处理）
return isSame;
```

- 比较二叉树外侧是否对称：传入的是左节点的左孩子，右节点的右孩子。
- 比较内侧是否对称，传入左节点的右孩子，右节点的左孩子。
- 如果左右都对称就返回 `true` ，有一侧不对称就返回 `false`。

##### 时间复杂度分析

从上到下每个节点仅被遍历一遍，所以时间复杂度是 `O(n)`。


## 解法二：迭代（使用队列）

通过队列来判断根节点的左子树和右子树的内侧和外侧是否相等，如动画所示：

![gif](https://code-thinking.cdn.bcebos.com/gifs/101.%E5%AF%B9%E7%A7%B0%E4%BA%8C%E5%8F%89%E6%A0%91.gif)


## 解法三：迭代（使用栈）

其实可以发现，这个迭代法，其实是把左右两个子树要比较的元素顺序放进一个容器，然后成对成对的取出来进行比较，那么其实使用栈也是可以的。

只要把队列原封不动的改成栈就可以了

