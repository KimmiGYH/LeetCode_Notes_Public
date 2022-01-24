# 2150_E_Find All Lonely Numbers in the Array_找出数组中的所有孤独数字

## 解法一：哈希表

- 按照题目要求用哈希表即可。
- 判断一个数是否存在最好用 $hash.count()$ 来做，否则容易创建 $hash[x]$ 到哈希表中，在某些卡常数的题目中（如 49题）会TLE
