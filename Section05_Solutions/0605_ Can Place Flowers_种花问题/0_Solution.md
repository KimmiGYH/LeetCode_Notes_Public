# 605. Can Place Flowers_种花问题 (Easy)



## 解法一：修改 flowerbed 的值



可以直接通过修改 `flowerbed` 的值来做，我们遍历花床，如果某个位置为 `0`，我们就看其前面一个和后面一个位置的值，注意处理首位置和末位置的情况，如果 `flowerbed[i - 1]` 和 `flowerbed[i + 1]` 均为 `0`，那么说明当前位置可以放花，我们修改 `flowerbed` 的值，并累加 `slots` 的值，最后看 `slots` 是否大于等于 `n`。

**时间复杂度**：
每个位置最多访问常数次，故时间复杂度为 $O(n)$。

## 解法二：

![solve_2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0605_%20Can%20Place%20Flowers_%E7%A7%8D%E8%8A%B1%E9%97%AE%E9%A2%98/solve2.png)

**01数组**，其中 `1` 表示已经放了花，`0` 表示可以放花的位置，但是有个限制条件是不能有相邻的花。

如果有 3 个连续的零，`000`，能放几盆花呢，其实是要取决于左右的位置：

- 如果两边都种了花，`10001`，只能放 1 盆
- 如果其中一边种了花，`0001`，只能放 1 盆（`1000` 也是同样的道理）
- 如果两边都没种花，`000`，只能放 2 盆

如果我们想通过计算连续 `0` 的个数，然后直接算出能放花的个数，就必须要对边界进行处理；

处理方法是如果首位置是 `0`，那么前面再加上个 `0`；如果末位置是 `0`，就在最后面再加上个 `0`。

这样处理之后我们就默认连续 `0` 的左右两边都是 `1` 了，相当于两边都种了花，这样如果有 `cnt` 个连续 `0`，那么就可以通过 `(cnt-1)/2` 来快速计算出能放的花的数量。



另外注意 `[1,0,1,0,1,0,1]` 的这种情况，需要分段计算 `slots` 并累加。

**时间复杂度**：
每个位置最多访问常数次，故时间复杂度为 $O(n)$。