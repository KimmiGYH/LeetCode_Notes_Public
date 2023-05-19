# 234. Palindrome Linked List_回文链表 (Easy)


## 解法一：快慢指针 + 反转链表



**算法**

整个流程可以分为以下五个步骤：

1. 找到前半部分链表的尾节点。
2. 反转后半部分链表。
3. 判断是否回文。
4. 恢复链表。
5. 返回结果。



1. 执行步骤一，我们可以计算链表节点的数量，然后遍历链表找到前半部分的尾节点。

   我们也可以使用快慢指针在一次遍历中找到：慢指针一次走一步，快指针一次走两步，快慢指针同时出发。当快指针移动到链表的末尾时，慢指针恰好到链表的中间。通过慢指针将链表分为两部分。

   若链表有奇数个节点，则中间的节点应该看作是前半部分。

2. 步骤二可以使用「206. 反转链表」问题中的解决方法来反转链表的后半部分。

3. 步骤三比较两个部分的值，当后半部分到达末尾则比较完成，可以忽略计数情况中的中间节点。

4. 步骤四与步骤二使用的函数相同，再反转一次恢复链表本身。



**复杂度分析**

时间复杂度：`O(n)`，其中 `n` 指的是链表的大小。

空间复杂度：`O(1)`。我们只会修改原本链表中节点的指向，而在堆栈上的。



作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode-solution/
来源：力扣（LeetCode）


## 解法三：放进vector中 + 双指针判断

通过链表判断序列是否为回文序列比较困难，
可以先遍历链表，把链表存储到 `vector` 容器中，
对 `vector` 容器中的数进行回文判断较为容易。

回文判断的思路：
双指针，一个从前向后，一个从后向前。
如果对应的数不一样则不是回文序列。
当两个指针相遇时退出循环。

需要注意链表为空的特殊情况。



**复杂度分析**

时间复杂度：`O(n)`，其中 `n` 指的是链表的元素个数。
第一步： 遍历链表并将值复制到数组中，`O(n)`。
第二步：双指针判断是否为回文，执行了 `O(n/2)` 次的判断，即 `O(n)`。
总的时间复杂度：`O(2n) = O(n)`。
空间复杂度：`O(n)`，其中 `n` 指的是链表的元素个数，我们使用了一个数组列表存放链表的元素值。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/palindrome-linked-list/solution/hui-wen-lian-biao-by-leetcode-solution/
来源：力扣（LeetCode）



## 知识点：`emplace_back`() vs `push_back()`

```cpp
vector<T>().push_back(T(args));
```

相当于

```cpp
vector<T>().emplace_back(args);
```

C++11之前，push_back先后调用了构造函数、拷贝构造函数（临时申请堆空间，影响性能）；

C++11之后，push_back先后调用了构造函数、转移构造函数。

在C++11的基础上，emplace_back比push_back少了一次转移构造函数，只有构造函数。

在www.cplusplus.com的std::vector::push_back的注解中，提到参数可能被拷贝或移动（即 左值引用 或 右值引用）：

> Adds a new element at the end of the vector, after its current last element. The content of val is **copied (or moved)** to the new element.

[https://my.oschina.net/xuejianhui0911/blog/2962037](https://my.oschina.net/xuejianhui0911/blog/2962037)

