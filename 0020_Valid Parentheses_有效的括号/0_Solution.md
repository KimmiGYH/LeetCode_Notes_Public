# 20. Valid Parentheses_有效的括号 (Easy)



## 解法一：用 ASCII码做

将符合条件的妹子放进 `stack` 中，男生与妹子进行匹配。

匹配时看 ASCII 码，`(` 与 `)`的ASCII码相差 `1`；`[` 与 `]`的ASCII码相差 `2`； `{` 与 `}` 的ASCII码相差 `2`。



所以判断条件可以写成：

```cpp
if (stk.size() && abs(stk.top() - c) <= 2) stk.pop();
```



