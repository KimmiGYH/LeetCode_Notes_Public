# [151. 表达式计算4](https://www.acwing.com/problem/content/description/153/)

**表达式求值问题，模板题背过即可。**

1. 建立一个用于存运算符的栈，逐一扫描该中缀表达式中的元素。
   1. 如果遇到一个数，输出该数。
   2. 如果遇到左括号 `(`，把左括号入栈。
   3. 如果遇到右括号 `)`，不断取出栈顶并输出，直到栈顶为左括号，然后把左括号出栈。
   4. 如果遇到运算符，**只要栈顶符号的优先级不低于新符号，就不断取出栈顶并输出**，最后把新符号进栈。优先级为：乘除 > 加减 > 左括号。
2. 依次取出并输出栈中的所有剩余符号，最终输出的序列就是一个与原中缀表达式等价的后缀表达式。

**以上例子中包含的都是一位数，如果是多位数，并且表达式是使用字符串逐字符存储的，我们只需要稍加判断，把连续的一段数字看成一个数即可。



视频：[https://www.acwing.com/video/74/](https://www.acwing.com/video/74/)

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section02_Templates/%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC/solve.png)



LeetCode类似题：

224. [Basic Calculator_基本计算器(Hard)](https://leetcode.com/problems/basic-calculator/) 只有 `+`、`-`，没有乘除，且不用考虑负数。
227. [Basic Calculator II_基本计算器 II (Medium)](https://leetcode.com/problems/basic-calculator-ii/) 有 `+`、`-` 、`*`、`/`，但不用考虑括号，且不用考虑负数。

