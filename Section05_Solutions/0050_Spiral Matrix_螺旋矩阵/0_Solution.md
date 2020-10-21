# 0050_Spiral Matrix_螺旋矩阵

改变方向direction的情况：

```cpp
if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] == 0)
```

- 1 Out of Boundary
- 2 已经走过了格子，需要提前标记一下

Sheep: https://youtu.be/4y4oJ7mKPfs

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0050_Spiral%20Matrix_%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5/solve.png)

