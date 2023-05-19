# 1190_Reverse Substrings Between Each Pair of Parentheses_反转每对括号间的子串

## 解法一：栈 $O(n^{2})$

- 本题解法一与力扣394. 字符串解码非常相似
步骤：
1. 创建一个放字符串的栈, 以及一个保存当前字符的变量
2. 遇到 `(` 就将当前的字符串推入栈, 并将当前字符串其设置为空
3. 遇到 `)` 就将当前的字符串反转, 然后与栈的顶部元素合并, 将栈的顶部元素弹出
4. 遇到普通的字符就将其添加到当前字符串的尾部
5. 遍历结束返回字符串

**复杂度分析**
- 时间复杂度：$O(n^{2})$，其中 $n$ 为字符串的长度。
  - 栈的最大深度为 $O(n)$
  - 每一层处理的时间复杂度主要为反转的时间复杂度，为 $O(n)$
  - 因此总时间复杂度为 $O(n^{2})$。
- 空间复杂度：$O(n)$，其中 $n$ 为字符串的长度。
  - 对于任意时刻，字符串中的任意一个字符至多只被栈中的一个位置包含一次。

## 解法二：预处理括号

还有第二种巧妙的解法，但是暂时有点看不懂，先放一放

[【每日一题】1190. Reverse Substrings Between Each Pair of Parentheses, 9/25/2020](https://www.youtube.com/watch?v=cY_z574Ax08&ab_channel=HuifengGuan)

[法二(括号预处理)](https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses/solution/zhan-dong-tu-yan-shi-by-xiaohu9527-hua8/)
