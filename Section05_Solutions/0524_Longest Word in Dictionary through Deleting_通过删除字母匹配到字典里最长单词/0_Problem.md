# [524. Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/) (Medium)

Given a string `s` and a string array `dictionary`, return *the longest string in the dictionary that can be formed by deleting some of the given string characters*. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 

**Example 1:**

```
Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
Output: "apple"
```

**Example 2:**

```
Input: s = "abpcplea", dictionary = ["a","b","c"]
Output: "a"
```

 

**Constraints:**

- `1 <= s.length <= 1000`
- `1 <= dictionary.length <= 1000`
- `1 <= dictionary[i].length <= 1000`
- `s` and `dictionary[i]` consist of lowercase English letters.



# [524. 通过删除字母匹配到字典里最长单词](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)

难度中等

给你一个字符串 `s` 和一个字符串数组 `dictionary` ，找出并返回 `dictionary` 中最长的字符串，该字符串可以通过删除 `s` 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

 

**示例 1：**

```
输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"
```

**示例 2：**

```
输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"
```

 

**提示：**

- `1 <= s.length <= 1000`
- `1 <= dictionary.length <= 1000`
- `1 <= dictionary[i].length <= 1000`
- `s` 和 `dictionary[i]` 仅由小写英文字母组成