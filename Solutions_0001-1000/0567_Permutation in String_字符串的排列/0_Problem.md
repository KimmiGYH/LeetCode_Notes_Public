# [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/) (Medium)

Given two strings `s1` and `s2`, return `true` *if* `s2` *contains a permutation of* `s1`*, or* `false` *otherwise*.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

 

**Example 1:**

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```

**Example 2:**

```
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
```

 

**Constraints:**

- `1 <= s1.length, s2.length <= 10^4`
- `s1` and `s2` consist of lowercase English letters.



# [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)

难度中等

给你两个字符串 `s1` 和 `s2` ，写一个函数来判断 `s2` 是否包含 `s1` 的排列。如果是，返回 `true` ；否则，返回 `false` 。

换句话说，`s1` 的排列之一是 `s2` 的 **子串** 。

 

**示例 1：**

```
输入：s1 = "ab" s2 = "eidbaooo"
输出：true
解释：s2 包含 s1 的排列之一 ("ba").
```

**示例 2：**

```
输入：s1= "ab" s2 = "eidboaoo"
输出：false
```

 

**提示：**

- `1 <= s1.length, s2.length <= 10^4`
- `s1` 和 `s2` 仅包含小写字母