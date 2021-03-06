# 1663_5606_Smallest String With A Given Numeric Value_具有给定数值的最小字符串 (Medium)



## 解法一：贪心 Greedy

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



## 解法二：数学 Math



- 首先将所有字符串都置为 `a`
- 从后往前，依次将第 `i` 位置成相应的字母，
- 使用 `(k - n) / 25` 计算出**需要置为 `z` 的个数**
- 然后通过 `(k - n) % 25` 计算出 `z` 之前的那一位应该置为多少



样例：

```
Input: n = 5, k = 73
Output: "aaszz"
```

如果 `n=5`，`k=73` ，首先定义字符串 “`aaaaa`”，同时；`k-5 = 68`。如果要按字典序升序，前面的字母必须尽可能小。从后往前遍历，最后一个 `a` 置为 `z`，`k-25 = 43`，此时 `k` 不为 `0` 且大于 `25`。继续倒数第二个 `a` 也置为 `z`，`k-25 = 18`。此时 `k` 大于 `0` 但小于 `25`，将倒数第 3 个 `a` 置为 `s` 即可结束。