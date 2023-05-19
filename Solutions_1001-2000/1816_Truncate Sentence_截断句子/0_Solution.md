# 1816_Truncate Sentence_截断句子

### 解法一：字符串模拟

- 将字符一个个遍历，遇到空格就 `k--`，如果 $k$ 为 $0$，就断开。
- 对于下面这个例子，将在 `k == 0` 之前将前四个单词输出。
```cpp
输入：s = "What is the solution to this problem", k = 4
输出："What is the solution"
```
- 而对于下面这个例子，`k = 5` 而空格只有 4 个，所以遍历到结尾循环会自动终止，不用担心多余的 k = 1 如何处理
```cpp
输入：s = "chopper is not a tanuki", k = 5
输出："chopper is not a tanuki"
```

### 解法二：字符串模拟 `substr`

- 由题意可知，除了最后一个单词，每个单词后面都跟随一个空格。如果空格数量小于 $k$，那么会先遍历到头，然后 $k$ 才等于 $0$
- 所以可以加 `if (s[i] == ' ' || i == n)` 这个条件，来统计 $cnt$
- 当 $cnt = k$ 时，将当前的下标记录到 $idx$，返回句子在 $s$ 在 $idx$ 处截断的句子。
