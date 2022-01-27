# 155_Min Stack_最小栈

## 解法一：栈 + 递推

[最小栈 （辅助栈法，清晰图解）](https://leetcode-cn.com/problems/min-stack/solution/min-stack-fu-zhu-stackfa-by-jin407891080/)

- 借用一个辅助栈 $minstk$，用于存获取 $stack$ 中最小值。

- 算法流程：
  - **`push()` **方法：每当 `push()` 新值进来时，如果 **小于等于** $minstk$ 栈顶值，则同时也 `push()` 到 $minstk$，即更新了栈顶最小值；
  - **`pop()`** 方法：判断将 $pop()$ 出去的元素值是否是 $minstk$ 栈顶元素值（即最小值），如果 `minstk.top() >= stk.top();` ，则将 $minstk$ 栈顶元素一起 `pop()`，这样可以保证 $minstk$ 栈顶元素始终是 $stack$ 中的最小值。
  
  - **`getMin()`** 方法： 返回 $minstk$ 栈顶即可。

最小栈的作用分析：
- $minstk$ 等价于遍历 $stack$ 所有元素，把升序的数字都删除掉，留下一个从栈底到栈顶降序的栈。
- 相当于给 $stack$ 中的降序元素做了标记，每当 `pop()` 这些降序元素，$minstk$ 会将相应的栈顶元素 `pop()` 出去，保证其栈顶元素始终是 $stack$ 中的最小元素。

**复杂度分析：**

- 时间复杂度 $O(1)$ ：压栈，出栈，获取最小值的时间复杂度都为 $O(1)$。
- 空间复杂度 $O(N)$ ：包含 $N$ 个元素辅助栈占用线性大小的额外空间。
