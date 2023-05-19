# 0050_Spiral Matrix_螺旋矩阵

**方向数组**那个写法能用的题还挺多的。

![方向数组](https://cdn.acwing.com/media/article/image/2022/02/22/41956_f13a474993-%E6%96%B9%E5%90%91%E6%95%B0%E7%BB%84.png)

## 改变方向direction的情况：

```cpp
if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0)
```

- 1 Out of Boundary
- 2 已经走过了格子，需要提前标记一下

Sheep: https://youtu.be/4y4oJ7mKPfs

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0054_Spiral%20Matrix_%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5/solve.png)

注意要开个 `bool`数组当标记比较安全。
`bool` 初始化的时候就是 `false`的，再设成 `false` 做标记是不是没什么意义，所以那个 `if` 会一直都进去，除非 12 行那边初始化 `check` 的时候把里面的所有元素都设成 `true`。