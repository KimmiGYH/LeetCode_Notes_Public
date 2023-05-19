# 2055. Plates Between Candles (Medium)

There is a long table with a line of plates and candles arranged on top of it. You are given a **0-indexed** string `s` consisting of characters `'*'` and `'|'` only, where a `'*'` represents a **plate** and a `'|'` represents a **candle**.

You are also given a **0-indexed** 2D integer array `queries` where `queries[i] = [lefti, righti]` denotes the **substring** `s[lefti...righti]` (**inclusive**). For each query, you need to find the **number** of plates **between candles** that are **in the substring**. A plate is considered **between candles** if there is at least one candle to its left **and** at least one candle to its right **in the substring**.

- For example, `s = "||**||**|*"`, and a query `[3, 8]` denotes the substring `"*||***\***|"`. The number of plates between candles in this substring is `2`, as each of the two plates has at least one candle **in the substring** to its left **and** right.

Return *an integer array* `answer` *where* `answer[i]` *is the answer to the* `ith` *query*.

 

**Example 1:**

![ex-1](https://assets.leetcode.com/uploads/2021/10/04/ex-1.png)

```
Input: s = "**|**|***|", queries = [[2,5],[5,9]]
Output: [2,3]
Explanation:
- queries[0] has two plates between candles.
- queries[1] has three plates between candles.
```

**Example 2:**

![ex-2](https://assets.leetcode.com/uploads/2021/10/04/ex-2.png)

```
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
```

 

**Constraints:**

- `3 <= s.length <= 10^5`
- `s` consists of `'*'` and `'|'` characters.
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= lefti <= righti < s.length`



# [2055. 蜡烛之间的盘子](https://leetcode-cn.com/problems/plates-between-candles/)

难度中等

给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 **0** 开始的字符串 `s` ，它只包含字符 `'*'` 和 `'|'` ，其中 `'*'` 表示一个 **盘子** ，`'|'` 表示一支 **蜡烛** 。

同时给你一个下标从 **0** 开始的二维整数数组 `queries` ，其中 `queries[i] = [lefti, righti]` 表示 **子字符串** `s[lefti...righti]` （**包含左右端点的字符**）。对于每个查询，你需要找到 **子字符串中** 在 **两支蜡烛之间** 的盘子的 **数目** 。如果一个盘子在 **子字符串中** 左边和右边 **都** 至少有一支蜡烛，那么这个盘子满足在 **两支蜡烛之间** 。

- 比方说，`s = "||**||**|*"` ，查询 `[3, 8]` ，表示的是子字符串 `"*||***\**\***|"` 。子字符串中在两支蜡烛之间的盘子数目为 `2` ，子字符串中右边两个盘子在它们左边和右边 **都** 至少有一支蜡烛。

请你返回一个整数数组 `answer` ，其中 `answer[i]` 是第 `i` 个查询的答案。

 

**示例 1:**

![ex-1](https://assets.leetcode.com/uploads/2021/10/04/ex-1.png)

```
输入：s = "**|**|***|", queries = [[2,5],[5,9]]
输出：[2,3]
解释：
- queries[0] 有两个盘子在蜡烛之间。
- queries[1] 有三个盘子在蜡烛之间。
```

**示例 2:**

![ex-2](https://assets.leetcode.com/uploads/2021/10/04/ex-2.png)

```
输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
输出：[9,0,0,0,0]
解释：
- queries[0] 有 9 个盘子在蜡烛之间。
- 另一个查询没有盘子在蜡烛之间。
```

 

**提示：**

- `3 <= s.length <= 10^5`
- `s` 只包含字符 `'*'` 和 `'|'` 。
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= lefti <= righti < s.length`

