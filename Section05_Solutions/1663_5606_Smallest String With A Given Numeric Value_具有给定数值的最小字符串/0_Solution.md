# 1663_5606_Smallest String With A Given Numeric Value_具有给定数值的最小字符串 (Medium)



数据范围：权值和在 `n ~ 26n `之间，一定能找到一个字符串使得字符串等于 `k` 的数值

全是 `a`： a a a ... a a a → n

全是 `z`：z z z ... z z z  →  26n



**思路与算法**

由于我们要使得构造出的字符串字典序最小，因此可以考虑贪心地从字符串的开头处开始构造，每次选择一个**满足要求的最小的字母**，即可得到最终答案。

那么怎样选择字母才是满足要求的呢？假设我们当前构造到了某一个位置，放入值为 `c` 的字母，

除开此位置还剩下 `m = n - i - 1` 个位置，

这些位置的数值之和为 `rest = k - s - c`，这个值必须满足：

`m <= rest <= 26 * m` 

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/1663_5606_Smallest%20String%20With%20A%20Given%20Numeric%20Value_%E5%85%B7%E6%9C%89%E7%BB%99%E5%AE%9A%E6%95%B0%E5%80%BC%E7%9A%84%E6%9C%80%E5%B0%8F%E5%AD%97%E7%AC%A6%E4%B8%B2/solve.png)



**复杂度分析**

- 时间复杂度：$O(n)$。
- 空间复杂度：$O(1)$。