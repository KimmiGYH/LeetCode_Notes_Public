# [30. Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) (Hard)

You are given a string `s` and an array of strings `words` of **the same length**. Return all starting indices of substring(s) in `s` that is a concatenation of each word in `words` **exactly once**, **in any order**, and **without any intervening characters**.

You can return the answer in **any order**.

 

**Example 1:**

```
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
```

**Example 2:**

```
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
```

**Example 3:**

```
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
```

 

**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of lower-case English letters.
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `words[i]` consists of lower-case English letters.



# [30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)

难度困难

给定一个字符串 `s` 和一些 **长度相同** 的单词 `words` **。**找出 `s` 中恰好可以由 `words` 中所有单词串联形成的子串的起始位置。

注意子串要与 `words` 中的单词完全匹配，**中间不能有其他字符** ，但不需要考虑 `words` 中单词串联的顺序。

 

**示例 1：**

```
输入：s = "barfoothefoobarman", words = ["foo","bar"]
输出：[0,9]
解释：
从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
```

**示例 2：**

```
输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
输出：[]
```

**示例 3：**

```
输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
输出：[6,9,12]
```

 

**提示：**

- `1 <= s.length <= 10^4`
- `s` 由小写英文字母组成
- `1 <= words.length <= 5000`
- `1 <= words[i].length <= 30`
- `words[i]` 由小写英文字母组成



