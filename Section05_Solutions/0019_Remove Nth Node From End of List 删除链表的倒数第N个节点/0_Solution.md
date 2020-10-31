# [19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) (Medium)

## 解法一：计算链表长度

![solve1](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0019_Remove%20Nth%20Node%20From%20End%20of%20List%20%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9/solve_1.png)

这道题⽐较简单，先循环⼀次拿到链表的总⻓度，
然后循环到要删除的结点的前⼀个节点 (前驱节点)，
跳过目标节点，
利用哑节点，避免头部情况
`dummy`     `1`     `2`     `3`     `4`     `5`     `NULL`

一次遍历链表，得到链表大小 `size = 5`，我们要删除第 `size + 1 - n` 个节点；



- 从 `i=0`, 跳`1`步可以跳到第`2`个点

​                     跳`2`步可以跳到第`3`个点

- 倒数第`( n )`个点是正数第`(size-n+1)`个点

- 倒数第`(n+1)`个点是正数第`(size-n)`个点

- 即跳`(size-n-1)`步可以跳到倒数第`(n+1)`个点



## 解法二：双指针（快慢指针）

[力扣视频题解](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/)

![solve2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0019_Remove%20Nth%20Node%20From%20End%20of%20List%20%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E7%9A%84%E5%80%92%E6%95%B0%E7%AC%ACN%E4%B8%AA%E8%8A%82%E7%82%B9/solve_2.png)

- 关键字：倒数第 `n` 个
- 模式识别：
  - 涉及链表的特殊位置，考虑快慢指针
  - 要删除链表节点，找到它的前驱



这道题有⼀种特别简单的解法。设置 2 个指针，⼀个指针距离前⼀个指针 n 个距离。同时移动 2 个指
针， 2 个指针都移动相同的距离。当⼀个指针移动到了终点，那么前⼀个指针就是倒数第 n 个节点了。  

比如，设置两个指针 `p`, `q`，让 `q` 先走 `n` 步，然后 `p` 和 `q` 一起走，直到 `q` 走到尾结点。
