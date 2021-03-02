# 575_Distribute Candies_分糖果（哈希表）



## 解法一：哈希表 $O(n)$



- 用 `unordered_set` 统计糖果的种类数，记为 `cnt`
- 比较数组长度的一半 `size/2` 与 糖果种类数，答案为  `min(cnt, size / 2)`

**时间复杂度**：

- 用 `unordered_set` 统计种类数的时间复杂度为 $O(n)$，然后 $O(1)$ 判断，故总时间复杂度为 $O(n)$。

