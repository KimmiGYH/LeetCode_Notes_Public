# 147. Insertion Sort List_对链表进行插入排序 (Medium)

```cpp
 //以下两行将cur节点插到 pre 和 pre->next 之间
            cur->next = pre->next;
            pre->next = cur;
```
