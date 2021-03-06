# 322. Coin Change_零钱兑换 (Medium)



## 解法一：动态规划-完全背包

**题目大意：**

给我们 `n` 种硬币（每种硬币有无限个），每个硬币有其面值 `vi`，让我们用最少的硬币凑一个总面值所需的个数。

**完全背包：**

体积 `Vi`，价值为 `1`，背包容量为 `amount`（或者写成 `m`）

举例：

```
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
```

**先放上完全背包的状态转移方程模板：**

- 完全背包二维：$f(i, j) = max( f(i-1, j), f(i, j - v) + w )$
- 完全背包一维：$f[j] = max( f[j], f[j - v[i]] + w[i] );$

因为硬币可以重复使用，因此这是一个完全背包问题。完全背包只需要将 **0-1 背包**的逆序遍历 dp 数组改为正序遍历即可。

**完全背包问题：**

- 物品：硬币
- 物品大小：面额
- 物品价值：数量

相当于有 $n$ 种物品，每种物品的体积大小是硬币面值，价值是 `1`。

问装满背包最少需要多少价值的物品？

**状态表示：**

$f[j]$ 表示凑出 $j$ 价值的钱，最少需要多少个硬币。

第一层循环枚举不同硬币，第二层循环从小到大枚举所有价值（由于每种硬币有无限多个，所以要从小到大枚举），然后用第 $i$ 种硬币更新 $f[j]$：

$完全背包一维：f[j] = min(f[j], f[j - coins[i]] + 1)$。



**时间复杂度分析：**

令 $n$ 表示硬币种数，$amount$ 表示总价钱，则总共两层循环，所以时间复杂度是 $O(nm)$。
