# 875_Koko Eating Bananas_爱吃香蕉的珂珂

## 解法一：二分

**思路分析**：

$\left \lceil \frac{q_{1}}{x}  \right \rceil +  \left \lceil \frac{q_{2}}{x}  \right \rceil + \cdots + \left \lceil \frac{q_{n}}{x}  \right \rceil \le n$

上取整的技巧：

$\left \lceil \frac{a}{b}  \right \rceil = \left \lfloor \frac{a + b - 1}{b}\right \rfloor$

二分的依据，判定 $n$ 个商店是否可以存放 $m$ 种商品，我们可以选择每次分配给一家商店最大的货物数量，记为 x，那么只要所有的 quantities 都按照这个分配给所有的商家，那么如果分配的商家个数小于等于 $n$，那么就表示：
- 这个分配方法是可以的，x 足够大了，所以可以把x以上的所有的分配方法筛选掉，即令 right = mid;
- 否则，表示此分配方法不能满足，就可以把 x 左边的分配方法筛选掉，即令 left = mid + 1;


**复杂度分析**：

- 时间复杂度：$O(m \log \max(quantities))$，这里 $m$ 是商品种数。我们在 $[1, \max{quantities}]$ 里使用二分查找定位每次分配给一家商店的最大货物数量；

- 空间复杂度：$O(1)$，算法只使用了常数个临时变量。
