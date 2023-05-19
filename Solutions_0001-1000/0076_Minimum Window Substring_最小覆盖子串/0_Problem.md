# 76. Minimum Window Substring (Hard)

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

**Example:**

```
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
```

**Note:**

- If there is no such window in S that covers all characters in T, return the empty string `""`.
- If there is such window, you are guaranteed that there will always be only one unique minimum window in S.



# [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/)

难度困难800

给你一个字符串 S、一个字符串 T 。请你设计一种算法，可以在 O(n) 的时间复杂度内，从字符串 S 里面找出：包含 T 所有字符的最小子串。

 

**示例：**

```
输入：S = "ADOBECODEBANC", T = "ABC"
输出："BANC"
```

 

**提示：**

- 如果 S 中不存这样的子串，则返回空字符串 `""`。
- 如果 S 中存在这样的子串，我们保证它是唯一的答案。



# 题目大意

给定⼀个源字符串 `s`，再给⼀个字符串 `T`，要求在源字符串中找到⼀个窗⼝，这个窗⼝包含由字符串各种排列组合组成的，窗⼝中可以包含 `T` 中没有的字符，如果存在多个，在结果中输出最⼩的窗⼝，如果找不到这样的窗⼝，输出空字符串。  

