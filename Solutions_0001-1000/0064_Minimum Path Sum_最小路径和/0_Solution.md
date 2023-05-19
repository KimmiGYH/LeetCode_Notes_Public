# 64. Minimum Path Sum

## 方法一：动态规划 $O(m*n)$

经典的动态规划题

- 状态表示：$f(i, j)$ 表示从起点到 `(i, j)` 的所有路径和的最小值；
  - 属性：$Min$

- 转移方程：$f(i, j) = min(f(i-1, j), f(i, j-1)) + grid(i, j) $
  - `grid[i,j]` 表示 `[i,j]` 的值。

```c++
if (i)    f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
if (j)    f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
```
