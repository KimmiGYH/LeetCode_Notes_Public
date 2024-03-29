# [921. Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/) (Medium)

A parentheses string is valid if and only if:

- It is the empty string,
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

- For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(**(**)))"` or a closing parenthesis to be `"())**)**)"`.

Return *the minimum number of moves required to make* `s` *valid*.

 

**Example 1:**

```
Input: s = "())"
Output: 1
```

**Example 2:**

```
Input: s = "((("
Output: 3
```

 

**Constraints:**

- `1 <= s.length <= 1000`
- `s[i]` is either `'('` or `')'`.



# [921. 使括号有效的最少添加](https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/)

难度中等

给定一个由 `'('` 和 `')'` 括号组成的字符串 `S`，我们需要添加最少的括号（ `'('` 或是 `')'`，可以在任何位置），以使得到的括号字符串有效。

从形式上讲，只有满足下面几点之一，括号字符串才是有效的：

- 它是一个空字符串，或者
- 它可以被写成 `AB` （`A` 与 `B` 连接）, 其中 `A` 和 `B` 都是有效字符串，或者
- 它可以被写作 `(A)`，其中 `A` 是有效字符串。

给定一个括号字符串，返回为使结果字符串有效而必须添加的最少括号数。

 

**示例 1：**

```
输入："())"
输出：1
```

**示例 2：**

```
输入："((("
输出：3
```

**示例 3：**

```
输入："()"
输出：0
```

**示例 4：**

```
输入："()))(("
输出：4
```

 

**提示：**

1. `S.length <= 1000`
2. `S` 只包含 `'('` 和 `')'` 字符。