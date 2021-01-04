# 509. Fibonacci Number_斐波那契数 (Easy)



## 解法一：动态规划DP

使用动态规划求解时要注意，如果没有一开始写

```c++
        if (n == 0)  return 0;
        if (n == 1)  return 1;
```

那么 `vector` 的长度定义为 `(n+2)`。



如果一开始写了 `return`，那么 `vector` 长度定义为 `(n+1)` 即可。



## 解法二：Fibonacci数性质

用 `while (n--)` 循环，直接利用 Fibonacci 数的性质。

