# 112. Path Sum_路径总和 (Easy)

## 解法一：(递归) $O(n)$

递归，自顶向下从根节点往叶节点走，每走过一个节点，就让 `sum` 减去该节点的值，则如果走到某个叶节点时，`sum` 恰好为 `0`，则说明从根节点到这个叶节点的路径上的数的和等于 `sum`。

只要找到一条满足要求的路径，递归即可返回。

##### 时间复杂度分析

每个节点仅被遍历一次，且递归过程中维护 `sum` 的时间复杂度是 `O(1)`，所以总时间复杂度是 `O(n)`。

参考：https://programmercarl.com/0112.%E8%B7%AF%E5%BE%84%E6%80%BB%E5%92%8C.html#%E8%A7%86%E9%A2%91%E8%AE%B2%E8%A7%A3

写法二：也可以正向写，只不过要多传一个变量。

## 解法二：迭代

如果使用栈模拟递归的话，那么如果做回溯呢？

此时栈里一个元素不仅要记录该节点指针，还要记录从头结点到该节点的路径数值总和。

c++就我们用pair结构来存放这个栈里的元素。
```cpp
定义为：pair<TreeNode*, int> pair<节点指针，路径数值>
```
这个为栈里的一个元素。

### 知识点：

本来要写成 `pair<TreeNode*, int>`
可以改用 `make_pair` 来代替。

一般 `make_pair` 都使用在需要 `pair` 做参数的位置，可以直接调用 `ake_pair` 生成 `pair` 对象。