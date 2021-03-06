# 382. Linked List Random Node_链表随机节点 (Medium)



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0382_Linked%20List%20Random%20Node_%E9%93%BE%E8%A1%A8%E9%9A%8F%E6%9C%BA%E8%8A%82%E7%82%B9/solve.png)



```c++
// 随机概率为 1/n
if (rand() % n == 0)  c = p->val;
```



##### 蓄水池抽样算法

如面经中出现在大数据流中的随机抽样问题。

即：当内存无法加载全部数据时，如何从包含未知大小的数据流中随机选取 `k` 个数据，并且要保证每个数据被抽取到的概率相等。

当 `k = 1` 时，即此题的情况；也就是说，我们每次只能读一个数据。

假设数据流含有 `N` 个数，我们知道如果要保证所有的数被抽到的概率相等，那么每个数抽到的概率应该为 `1/N`。

##### 那如何保证呢？

先说方案：

每次只保留一个数，当遇到第 `k` 个数时，以 `1/k` 的概率保留它，`(k-1)/k` 的概率保留原来的数。

举例说明： `1 ~ 10`

遇到 `1`，概率为 `1`，保留第一个数；
遇到 `2`，概率为 `1/2`，这个时候，1和2各1/2的概率被保留；
遇到 `3`，`3` 被保留的概率为 `1/3`，(之前剩下的数假设 `1` 被保留)，`2/3` 的概率 `1` 被保留，(此时 `1` 被保留的总概率为 `2/3 * 1/2 = 1/3`)；
遇到 `4`，`4` 被保留的概率为 `1/4`，(之前剩下的数假设 `1` 被保留)，`3/4` 的概率 `1` 被保留，(此时 `1` 被保留的总概率为 `3/4 * 2/3 * 1/2 = 1/4`)；
以此类推，每个数被保留的概率都是`1/N`。

作者：jackwener
链接：https://leetcode-cn.com/problems/linked-list-random-node/solution/xu-shui-chi-chou-yang-suan-fa-by-jackwener/

