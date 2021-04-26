# [1839. Longest Substring Of All Vowels in Order](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/) (Medium)

A string is considered **beautiful** if it satisfies the following conditions:

- Each of the 5 English vowels (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`) must appear **at least once** in it.
- The letters must be sorted in **alphabetical order** (i.e. all `'a'`s before `'e'`s, all `'e'`s before `'i'`s, etc.).

For example, strings `"aeiou"` and `"aaaaaaeiiiioou"` are considered **beautiful**, but `"uaeio"`, `"aeoiu"`, and `"aaaeeeooo"` are **not beautiful**.

Given a string `word` consisting of English vowels, return *the **length of the longest beautiful substring** of* `word`*. If no such substring exists, return* `0`.

A **substring** is a contiguous sequence of characters in a string.

 

**Example 1:**

```
Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
```

**Example 2:**

```
Input: word = "aeeeiiiioooauuuaeiou"
Output: 5
Explanation: The longest beautiful substring in word is "aeiou" of length 5.
```

**Example 3:**

```
Input: word = "a"
Output: 0
Explanation: There is no beautiful substring, so return 0.
```

 

**Constraints:**

- `1 <= word.length <= 5 * 10^5`
- `word` consists of characters `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.



# [1839. 所有元音按顺序排布的最长子字符串](https://leetcode-cn.com/problems/longest-substring-of-all-vowels-in-order/)

难度中等

当一个字符串满足如下条件时，我们称它是 **美丽的** ：

- 所有 5 个英文元音字母（`'a'` ，`'e'` ，`'i'` ，`'o'` ，`'u'`）都必须 **至少** 出现一次。
- 这些元音字母的顺序都必须按照 **字典序** 升序排布（也就是说所有的 `'a'` 都在 `'e'` 前面，所有的 `'e'` 都在 `'i'` 前面，以此类推）

比方说，字符串 `"aeiou"` 和 `"aaaaaaeiiiioou"` 都是 **美丽的** ，但是 `"uaeio"` ，`"aeoiu"` 和 `"aaaeeeooo"` **不是美丽的** 。

给你一个只包含英文元音字母的字符串 `word` ，请你返回 `word` 中 **最长美丽子字符串的长度** 。如果不存在这样的子字符串，请返回 `0` 。

**子字符串** 是字符串中一个连续的字符序列。

 

**示例 1：**

```
输入：word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
输出：13
解释：最长子字符串是 "aaaaeiiiiouuu" ，长度为 13 。
```

**示例 2：**

```
输入：word = "aeeeiiiioooauuuaeiou"
输出：5
解释：最长子字符串是 "aeiou" ，长度为 5 。
```

**示例 3：**

```
输入：word = "a"
输出：0
解释：没有美丽子字符串，所以返回 0 。
```

 

**提示：**

- `1 <= word.length <= 5 * 10^5`
- `word` 只包含字符 `'a'`，`'e'`，`'i'`，`'o'` 和 `'u'` 。