# 107. Binary Tree Level Order Traversal II_二叉树的层次遍历 II (Easy)



与102题基本相同，只要最后将二维数组翻转一下即可。

```cpp
        reverse(res.begin(), res.end());
```

```cpp
[
  [3],
  [9,20],
  [15,7]
]

就变成了：

[
  [15,7],
  [9,20],
  [3]
]
```



