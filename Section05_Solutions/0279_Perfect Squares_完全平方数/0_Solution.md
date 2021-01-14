# 279. Perfect Squares_完全平方数 (Medium)



## 解法一：BFS

$$
（宽度优先搜索）BFS: O(n\sqrt n)
$$

<u>6-5 BFS和图的最短路径 Perfect Squares (16:30)</u>

**对问题建模：求从 `n` 到 `0` 的最短路。**

整个问题转化为一个图论问题。

从 `n` 到 `0`，每个数字表示一个节点；

如果两个数字 `x` 到 `y` 相差一个完全平方数，则连接一条边。

我们得到了一个无权图。

原问题转化成，求这个无权图中从 `n` 到 `0` 的最短路径。



##### 时间复杂度

- 宽搜的时间复杂度为 `O(n+m)`，这里的点数，也就是数字个数 `n`，边数的分析是 `O(√i)`。
- 故总时间复杂度仍然是  `O(n√n)` ，但由于宽搜可能能快速找到到结点 `n` 的路径，常数会比较优。

##### 空间复杂度

需要额外 `O(n)` 的空间存储队列和距离数组。



![solve_1](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0279_Perfect%20Squares_%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0/solve_1.png)



## 解法二：动态规划 - 完全背包问题 Dynamic Programming

$$
(动态规划): O(n\sqrt n)
$$

- $n$：背包容量
- 体积：1、4、9、16 等平方数，把每个数的数值当成体积
- 价值：把每个数的价值当成 $1$
- 求在恰好装满背包的前提下，总价值最小是多少

```cpp
// 完全背包问题 代码模板

int f[M];   // f[j]表示背包容量为j条件下的最大价值
for(int i = 1; i <= n; ++i) 
    for(int j = v[i]; j <= m; ++j)
        f[j] = max(f[j], f[j - v[i]] + w[i]);
```

1. 设 `dp[i]` 表示通过平方数组成 `i` 所需要完全平方数的最少数量。
2. 初始时，`dp[0] = 0`，其余待定。
3. 转移时，对于一个 `i`，枚举 `j`，`dp[i] = min(dp[i - j*j] + 1)`，其中 `1≤j≤√i`。
4. 最终答案为 `dp[n]`。



##### 时间复杂度

- `O(n√n)`

##### 空间复杂度

- 需要额外 `O(n)` 的空间存储状态。



![solve_2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0279_Perfect%20Squares_%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0/solve_2.png)



## 解法三：数学 Math

[参考文档](https://www.acwing.com/solution/content/300/)
$$
(数学): O(\sqrt n +log n)
$$

1. 根据 [拉格朗日四平方和定理 Lagrange's four-square theorem](https://en.wikipedia.org/wiki/Lagrange%27s_four-square_theorem)，可以得知答案必定为 `1, 2, 3, 4` 中的一个。

2. 其次根据 [勒让德三平方和定理 Legendre's three-square theorem](https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem)，可以得知当且仅当 n != 4^a^(8b+7) 时，`n` 能写成 `3` 个数的平方和。
   $$
   当且仅当 \ n  \ != 4^a (8b + 7) 时，n = x^2 + y ^2 + z^2
   $$
   
3. 然后可以根据以上定理和枚举，判断出答案是否为 `1, 2, 3`，若都不是则答案为 `4`。



##### 时间复杂度

判断平方数的时间复杂度为 `O(1)`，

枚举答案为 `2` 的时间复杂度为 `O(√n)`，

判断答案是否为 `4` 的时间复杂度为 `O(logn)`，

故总时间复杂度为 `O(√n + logn)`。









