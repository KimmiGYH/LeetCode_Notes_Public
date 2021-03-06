# 219. Contains Duplicate II_存在重复元素 II



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0219_Contains%20Duplicate%20II_%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0%20II/solve.png)



## 解法一：维护`map`中只有`k`个元素

这道题可以维护⼀个只有 `K` 个元素的 `map`，每次只需要判断这个 `map` ⾥⾯是否存在这个元素即可。

如果存在就代表重复数字的下标差值在 `K` 以内。 `map` 的⻓度如果超过了 `K` 以后就删除掉 `i-k` 的那个元素，这样⼀直维护 `map` ⾥⾯只有 `K` 个元素。

时间复杂度：O(n)

空间复杂度：O(k)



## 解法二：

我们只关心离 `i` 最近的一个数，离 `i` 最近就意味着 `j` 和 `i` 的差越小，就越有可能满足要求。

用 `map` 存一下每个数的位置是什么。

当枚举 `ai` 时，我们需要看一下和 `ai` 相同的最后一个数的位置是什么 `j = hash[ai]`；

```c++
// 如果x在之前出现过，且i减去x之前出现的最后一次位置hash[x]小于等于k的话
if (hash.count(x) && i - hash[x] <= k)  return true;
```

之后需要更新一下位置 `hash[ai] = i`。

时间复杂度：O(n)



