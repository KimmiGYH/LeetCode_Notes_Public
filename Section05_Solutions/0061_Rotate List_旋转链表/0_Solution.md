# 61. Rotate List_旋转链表 (Medium)



这道题需要注意的点是， `K` 可能很⼤， `K = 2000000000` ，如果是循环肯定会超时。应该找出 `O(n)` 的复杂度的算法才⾏。

由于是循环旋转，最终状态其实是确定的，利⽤链表的⻓度取余可以得到链表的最终旋转结果。

(模拟，链表) `O(n)`

- 这道题中 `k` 可能很大，所以我们令 `k %= n`，`n` 是链表长度。注意 `n` 要判空。
- 求出三个节点的位置
  - 原链表的 `tail`
  - 中间位置处的前段的尾节点 `p` 
  - `p` 后面的那个节点，新链表的 `head` 节点



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0061_Rotate%20List_%E6%97%8B%E8%BD%AC%E9%93%BE%E8%A1%A8/solve.png)



