# 64. Minimum Path Sum

## 方法一：动态规划

`f[i][j]` 表示从起点到 `f[i,j]` 的所有路径的最小值；

`grid[i,j]` 表示 [i,j] 的值

```cpp
                    if (i)
                        f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                    if (j)
                        f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
```
