# 143_Reorder List_重排链表

- 这题需要 876、206、92题的基础
- 视频讲解：[【环形链表II【基础算法精讲 07】】 【精准空降到 05:35】](https://www.bilibili.com/video/BV1KG4y1G7cu/?share_source=copy_web&vd_source=672840fcf5c68492bb4e1f49d5c87506&t=335)
- 可以直接寻找链表中点 `len / 2 + 1`
- 也可以用快慢指针来做

以前的题解：
## 解法一：寻找链表中点 + 反转链表 + 合并链表

找到原链表的中点，记得最后还要分奇偶来给尾节点的`next`节点赋为`nullptr`。



## 解法二：使用快慢指针来找链表中点 + 反转链表 + 合并链表



这样我们的任务即可划分为三步：

- 1. 找到原链表的中点（参考「[876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)」）。

     我们可以使用**快慢指针**来 `O(N)` 地找到链表的中间节点。

- 2. 将原链表的右半端反转（参考「[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)」）。

     我们可以使用迭代法实现链表的反转。

- 3. 将原链表的两端合并。



*用了快慢指针就不需要最后分奇偶给尾节点的`next`节点赋空`nullptr`。

