# 203. Remove Linked List Elements_移除链表元素 (Easy)

## 删除节点模板

### (1) 直接使用原来的链表来进行移除节点操作：

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头结点
        while (head != NULL && head->val == val) { // 注意这里不是if
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        // 删除非头结点
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
```

### (2) 设置一个虚拟头结点在进行移除节点操作：

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
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