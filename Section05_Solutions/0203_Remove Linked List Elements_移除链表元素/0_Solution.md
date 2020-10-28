# 203. Remove Linked List Elements_移除链表元素 (Easy)

删除节点：

```cpp
delNode = cur->next;
cur->next = delNode->next;
```

两种写法：

## 写法一：while

```cpp
while (cur->next) {
    if (cur->next->val == val) {
        // 删除 cur->next
        ListNode* delNode = cur->next;
        cur->next = delNode->next;
    }
    else
        cur = cur->next;
}
```



## 写法二：for

```cpp
for (auto cur = dummy; cur; cur = cur->next ) {
    auto delNode = cur->next;
    while (delNode && delNode-val == val)
        delNode = delNode->next;
    cur->next = delNode;
}
```



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0203_Remove%20Linked%20List%20Elements_%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0/solve.png)