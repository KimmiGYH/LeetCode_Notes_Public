# 224. Basic Calculator_基本计算器(Hard)

## 栈 + 表达式求值 $O(n)$

**表达式求值问题。原则：能算就算**

`(`、`)`、`+`、`-`、`x`、`/`、`^`

- ① 如果是数字，压入栈中
- ② 如果是左括号，压入栈中
- ③ 如果是右括号，则将括号内的都算完
- ④ 运算符`+`、`-`、`x`、`/`、`^`，可以定义运算符的优先级
  - 当前运算符优先级 $\le$ 栈顶，则优先处理栈顶运算符计算，之后也要压入栈中
  - 当前运算符优先级 $>$ 栈顶，则压入栈中
  - 优先级可以用 `unordered_map` 来存


开两个栈，一个记录数字，一个记录操作符。

然后从前往后扫描整个表达式：

1. 如果遇到 `(`、`+`、`-`，直接入栈；
2. 如果遇到数字，则判断操作符栈的栈顶元素，
   如果不是 `(`而是运算符，则弹出操作符的栈顶运算符，并用相应操作更新**数字栈**的栈顶元素。从而保证**操作符栈**的栈顶最多有一个连续的 `+` 或 `-`；
3. 如果遇到 `)`，如果操作符栈顶不是 `(`而是运算符，则操作符计算并弹出栈顶操作符；如果是 `(` 则将其左括号弹出。
4. 然后根据新栈顶的操作符，对数字栈顶的两个元素进行相应操作；
5. 特殊处理符号和正号
    ```cpp
                    if (!i || s[i-1] == '(' || s[i-1] == '+' || s[i-1] == '-')
                        num.push(0);// 特殊处理符号和正号
    ```
**时间复杂度分析**：
- 每个数字和操作进栈出栈一次，所以总时间复杂度是 $O(n)$。

