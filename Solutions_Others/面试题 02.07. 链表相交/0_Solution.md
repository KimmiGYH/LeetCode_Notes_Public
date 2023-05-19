# 面试题 02.07. 链表相交

## 解法一：

简单来说，就是求两个链表交点节点的**指针**。 这里同学们要注意，交点不是数值相等，而是指针相等。

为了方便举例，假设节点元素数值相等，则节点指针相等。

看如下两个链表，目前 `curA` 指向链表A的头结点，`curB`指向链表B的头结点：

![面试题02.07.链表相交_1.png](https://code-thinking.cdn.bcebos.com/pics/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4_1.png)



我们求出两个链表的长度，并求出两个链表长度的差值，然后让 `curA` 移动到和 `curB`末尾对齐的位置，如图： 

![面试题02.07.链表相交_2.png](https://code-thinking.cdn.bcebos.com/pics/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4_2.png)

注意：条件中写的 

- 如果 `listA` 和 `listB` 有交点，`intersectVal == listA[skipA + 1] == listB[skipB + 1]`

表示的是，如果 `listA` 和 `listB` 有交点，那么后面的节点也都一样。



此时我们就可以比较 `curA` 和 `curB` 是否相同，如果不相同，同时向后移动 `curA` 和 `curB`，如果遇到 `curA == curB`，则找到交点。

否则循环退出返回空指针。


**复杂度分析**
- 时间复杂度：$O(n + m)$
- 空间复杂度：O(1)

参考：https://programmercarl.com/%E9%9D%A2%E8%AF%95%E9%A2%9802.07.%E9%93%BE%E8%A1%A8%E7%9B%B8%E4%BA%A4.html#%E6%80%9D%E8%B7%AF


## 解法二：

[面试题 02.07. 链表相交（双指针，清晰图解）](https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/solutions/1190240/mian-shi-ti-0207-lian-biao-xiang-jiao-sh-b8hn/)

这个题解太高级，看得不是特别明白，肯定也写不出来。
