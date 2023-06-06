# 429_N-ary Tree Level Order Traversal_N 叉树的层序遍历



# 解法一：层序遍历



注意：N 叉树遍历的不只是左右儿子，而是 N 个儿子，所以：

```cpp
for (auto& c : t->children)
    q.push(c);
```





