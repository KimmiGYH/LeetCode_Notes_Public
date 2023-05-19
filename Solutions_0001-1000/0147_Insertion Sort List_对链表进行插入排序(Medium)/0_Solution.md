# 147. Insertion Sort List_对链表进行插入排序 (Medium)



```cpp
 //以下两行将cur节点插到 p 和 p->next 之间
            cur->next = p->next;
            p->next = cur;
```



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0147_Insertion%20Sort%20List_%E5%AF%B9%E9%93%BE%E8%A1%A8%E8%BF%9B%E8%A1%8C%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F(Medium)/solve_1.png)