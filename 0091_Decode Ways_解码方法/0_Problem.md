# [91. Decode Ways](https://leetcode.com/problems/decode-ways/) (Medium)

A message containing letters from `A-Z` can be **encoded** into numbers using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```

To **decode** an encoded message, all the digits must be mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, `"111"` can have each of its `"1"`s be mapped into `'A'`s to make `"AAA"`, or it could be mapped to `"11"` and `"1"` (`'K'` and `'A'` respectively) to make `"KA"`. Note that `"06"` cannot be mapped into `'F'` since `"6"` is different from `"06"`.

Given a **non-empty** string `num` containing only digits, return *the **number** of ways to **decode** it*.

The answer is guaranteed to fit in a **32-bit** integer.

 

**Example 1:**

```
Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
```

**Example 2:**

```
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

**Example 3:**

```
Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with 0. The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20".
Since there is no character, there are no valid ways to decode this since all digits need to be mapped.
```

**Example 4:**

```
Input: s = "1"
Output: 1
```

 

**Constraints:**

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zero(s).



# [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)

难度中等

一条包含字母 `A-Z` 的消息通过以下方式进行了编码：

```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

给定一个只包含数字的**非空**字符串，请计算解码方法的总数。

题目数据保证答案肯定是一个 32 位的整数。

 

**示例 1：**

```
输入：s = "12"
输出：2
解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
```

**示例 2：**

```
输入：s = "226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
```

**示例 3：**

```
输入：s = "0"
输出：0
```

**示例 4：**

```
输入：s = "1"
输出：1
```

**示例 5：**

```
输入：s = "2"
输出：1
```

 

**提示：**

- `1 <= s.length <= 100`
- `s` 只包含数字，并且可能包含前导零。

