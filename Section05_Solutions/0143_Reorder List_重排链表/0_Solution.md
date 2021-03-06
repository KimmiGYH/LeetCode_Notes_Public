

## 解法一：寻找链表中点 + 反转链表 + 合并链表

找到原链表的中点，记得最后还要分奇偶来给尾节点的`next`节点赋为`nullptr`。

![solve1](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0143_Reorder%20List_%E9%87%8D%E6%8E%92%E9%93%BE%E8%A1%A8/solve1.png)

## 解法二：使用快慢指针来找链表中点 + 反转链表 + 合并链表



这样我们的任务即可划分为三步：

- 1. 找到原链表的中点（参考「[876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)」）。

     我们可以使用**快慢指针**来 `O(N)` 地找到链表的中间节点。

- 2. 将原链表的右半端反转（参考「[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)」）。

     我们可以使用迭代法实现链表的反转。

- 3. 将原链表的两端合并。



*用了快慢指针就不需要最后分奇偶给尾节点的`next`节点赋空`nullptr`。

