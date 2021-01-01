# 495. Teemo Attacking_提莫攻击 (Medium)



**贪心 Greedy** $O(n)$

直接使用贪心算法，比较相邻两个时间点的时间差 `difference = timeSeries[i] - timeSeries[i - 1]`，

- 如果小于 `duration`，就加上这个 `difference`，
- 如果大于或等于`duration`，就加上 `duration`，
- 第一、二步可以直接用 `min()` 来取较小数，
- 最后的中毒持续时间别忘记， `res += duration`

 

