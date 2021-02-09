# 304_Range Sum Query 2D - Immutable_二维区域和检索-矩阵不可变 (Medium)

## 解法一：二维前缀和

![二维前缀和.png](https://cdn.acwing.com/media/article/image/2021/02/09/41956_f77638706a-二维前缀和.png) 

1. $S[i,j]$ 即为图1 红框中所有数的和为：

    $S[i, \ j] = S[i, \ j-1] + S[i-1, \ j] - S[i-1, \ j-1] + a[i, \ j]$

2. $(x1,y1)$，$(x2,y2)$ 这一子矩阵中的所有数之和为：

    $S[x_{2}, \ y_{2}] - S[x_{1} - 1, \ y_{2}] - S[x_{2}, \ y_{1} - 1] + S[x_{1} - 1, \ y_{1} - 1]$

注意下标
