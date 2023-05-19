# [791. Custom Sort String](https://leetcode.com/problems/custom-sort-string/) (Medium)

You are given two strings order and s. All the words of `order` are **unique** and were sorted in some custom order previously.

Permute the characters of `s` so that they match the order that `order` was sorted. More specifically, if a character `x` occurs before a character `y` in `order`, then `x` should occur before `y` in the permuted string.

Return *any permutation of* `s` *that satisfies this property*.

 

**Example 1:**

```
Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.
```

**Example 2:**

```
Input: order = "cbafg", s = "abcd"
Output: "cbad"
```

 

**Constraints:**

- `1 <= order.length <= 26`
- `1 <= s.length <= 200`
- `order` and `s` consist of lowercase English letters.
- All the characters of `order` are **unique**.



# [791. 自定义字符串排序](https://leetcode-cn.com/problems/custom-sort-string/)

难度中等

字符串`S`和 `T` 只包含小写字符。在`S`中，所有字符只会出现一次。

`S` 已经根据某种规则进行了排序。我们要根据`S`中的字符顺序对`T`进行排序。更具体地说，如果`S`中`x`在`y`之前出现，那么返回的字符串中`x`也应出现在`y`之前。

返回任意一种符合条件的字符串`T`。

```
示例:
输入:
S = "cba"
T = "abcd"
输出: "cbad"
解释: 
S中出现了字符 "a", "b", "c", 所以 "a", "b", "c" 的顺序应该是 "c", "b", "a". 
由于 "d" 没有在S中出现, 它可以放在T的任意位置. "dcba", "cdba", "cbda" 都是合法的输出。
```

**注意:**

- `S`的最大长度为`26`，其中没有重复的字符。
- `T`的最大长度为`200`。
- `S`和`T`只包含小写字符。