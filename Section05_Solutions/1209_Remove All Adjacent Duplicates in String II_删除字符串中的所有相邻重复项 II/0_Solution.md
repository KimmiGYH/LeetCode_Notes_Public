# 1209_Remove All Adjacent Duplicates in String II_删除字符串中的所有相邻重复项 II

## 解法一：栈

```cpp
例2：
输入：s = "deeedbbcccbdaa", k = 3
输出："aa"
解释： 
先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
再删除 "bbb"，得到 "dddaa"
最后删除 "ddd"，得到 "aa"
```

- 用 `pair<char, int>` 来记录字符和它出现的次数
- 如果是新字符，压栈内容为 `stk.push({c, 1});`
- 如果是重复字符，则压栈内容为 `stk.push({c, stk.top().second + 1})`
- 如果 `stk.top().second == k`，则弹栈（开心消消乐）
- 最后记录字符串，从栈 `push` 到 `string`时是倒序，所以最后还要 `reverse` 字符串。
