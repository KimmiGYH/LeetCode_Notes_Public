# 518_Coin Change 2_零钱兑换 II (Medium)

(动态规划，完全背包)  $O(amount \cdot n)$

1. 将总金额视为背包容量，将硬币的面额视为体积，价值视为 `1`，此题就是变种的固定容量完全背包问题。
   - 背包容量：总金额
   - 每枚硬币：物品
   - 体积：面额

2. 设状态 $f(j)$ 表示硬币总面额为 $j$ 时的方案数。
3. 初始时 $f(0) = 1$。
4. 对于每一种硬币面额 $coins(i)$，$j$ 从 $coins(i)$ 枚举到 $amount$，累计转移 $f(j) = f(j) + f(j - coins(i))$。
5. 最终答案为 $f(amount)$。

**时间复杂度：**

- 状态数为 $O(amount)$，转移总数为 $O(n)$，每次转移的时间复杂度为 $O(1)$，故总时间复杂度为 $O(amount \cdot n)$。
