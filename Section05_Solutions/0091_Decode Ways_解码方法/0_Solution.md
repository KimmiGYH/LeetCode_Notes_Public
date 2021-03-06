# 91. Decode Ways_解码方法 (Medium)



这道题要求解码方法，跟之前那道 70. Climbing Stairs 非常的相似，但是还有一些其他的限制条件，比如说一位数时不能为`0`，两位数不能大于 `26`，其十位上的数也不能为 `0`，除去这些限制条件，跟爬梯子基本没啥区别，需要用动态规划 Dynamci Programming 来解。



建立一维 dp 数组，其中 `dp[i]` 表示 `s` 中前 `i` 个字符组成的子串的解码方法的个数，长度比输入数组多 `1`，并将 `dp[0]` 初始化为`1`。

`0` 是个很特殊的存在：

- 若当前位置是 `0`，则一定无法单独拆分出来，即不能加上 `dp[i-1]`；
- 再看能否跟前一个数字组成大于等于 10 且小于等于 26 的数，能的话可以加上 `dp[i-2]`，否则就只能保持为 `0` 。



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0091_Decode%20Ways_%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95/solve.png)



拿题目中的**例子2**来分析：

**示例 2：**

```
输入：s = "226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
```

![example2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0091_Decode%20Ways_%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95/example2.png)