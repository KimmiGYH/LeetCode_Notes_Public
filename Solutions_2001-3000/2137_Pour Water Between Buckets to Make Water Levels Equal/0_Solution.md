# 2137_Pour Water Between Buckets to Make Water Levels Equal

## 解法一：小数二分

思路：
- 经典的**小数**二分查找，我们对最终的水桶水量进行二分，最大值 $r$ 设为原水桶水量的平均值
- 设最终水桶平均值为 $m$，每次我们将水桶水量 $bucket$ 大于 $m$ 的累加为剩余的水量 $remain$；将水桶水量 $bucket$ 小于 $m$ 的累加为 $need$，即需要的水量
- 判断其大小关系即可，如果剩余的水量 $\times$ 剩余的百分比 的值能满足所需求的水量，那么 $check$ 函数返回 $true$
