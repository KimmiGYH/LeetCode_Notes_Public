# 203. Remove Linked List Elements_移除链表元素 (Easy)

删除节点：

```cpp
delNode = cur->next;
cur->next = delNode->next;
```

两种写法：

## 写法一：while

```cpp
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next; //保存cur->next
                cur->next = tmp->next;
                delete tmp; //删掉该节点
            } else {
                cur = cur->next;
            }
        }
```



## 写法二：for

```cpp
        for (ListNode* cur = dummy; cur; cur = cur->next) {
            ListNode* delNode = cur->next;
            while(delNode && delNode->val == val)
                delNode = delNode->next;
            cur->next = delNode;
        }
```



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0203_Remove%20Linked%20List%20Elements_%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0/solve.png)