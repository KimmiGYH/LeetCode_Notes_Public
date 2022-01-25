# [895. Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack/) (Hard)

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the `FreqStack` class:

- `FreqStack()` constructs an empty frequency stack.

- `void push(int val)` pushes an integer `val` onto the top of the stack.

- `int pop()`  removes and returns the most frequent element in the stack.
- If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

 

**Example 1:**

```
Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
```

 

**Constraints:**

- `0 <= val <= 10^9`
- At most `2 * 10^4` calls will be made to `push` and `pop`.
- It is guaranteed that there will be at least one element in the stack before calling `pop`.



# [895. 最大频率栈](https://leetcode-cn.com/problems/maximum-frequency-stack/)

难度困难

实现 `FreqStack`，模拟类似栈的数据结构的操作的一个类。

`FreqStack` 有两个函数：

- `push(int x)`，将整数 `x` 推入栈中。

- `pop()` ，它 移除 并返回栈中出现最频繁的元素。

  - 如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。

 

**示例：**

```
输入：
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
输出：[null,null,null,null,null,null,null,5,7,5,4]
解释：
执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

pop() -> 返回 5，因为 5 是出现频率最高的。
栈变成 [5,7,5,7,4]。

pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
栈变成 [5,7,5,4]。

pop() -> 返回 5 。
栈变成 [5,7,4]。

pop() -> 返回 4 。
栈变成 [5,7]。
```

 

**提示：**

- 对 `FreqStack.push(int x)` 的调用中 `0 <= x <= 10^9`。
- 如果栈的元素数目为零，则保证不会调用 `FreqStack.pop()`。
- 单个测试样例中，对 `FreqStack.push` 的总调用次数不会超过 `10000`。
- 单个测试样例中，对 `FreqStack.pop` 的总调用次数不会超过 `10000`。
- 所有测试样例中，对 `FreqStack.push` 和 `FreqStack.pop` 的总调用次数不会超过 `150000`。