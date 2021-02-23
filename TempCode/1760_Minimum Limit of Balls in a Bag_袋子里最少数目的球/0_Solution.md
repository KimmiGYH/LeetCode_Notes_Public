# 1760_Minimum Limit of Balls in a Bag_袋子里最少数目的球 (Medium)

**思路与算法：**

首先转换成判定问题，即：

> 给定 $maxOperations$ 次操作次数，能否可以使得单个袋子里球数目的最大值不超过 $y$。

由于当 $y$ 增加时，操作次数会减少，因此 $y$ 具有单调性，我们可以通过二分查找的方式得到答案。

事实上，如果单个袋子里有 $x$ 个球，那么操作次数即为： $$\left \lfloor \frac{x-1}{y}  \right \rfloor$$

其中 $\left \lfloor x \right \rfloor $ 表示将 $x$ 进行下取整。因此我们需要找到最小的 $y$，使得：

$$\sum_{x\in nums}^{} \left \lfloor \frac{x-1}{y}  \right \rfloor \le \ maxOperations$$

成立。
