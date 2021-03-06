# 0684_Redundant Connection_冗余连接 (Medium)

## 方法一：并查集

这道题最好的解法使用 Union Find 来做

Union Find 的核心思想并不是很难理解，首先建立一个长度为 `(n+1)` 的数组 root，由于这道题并没有明确的说明 `n` 是多少，只是说了输入的二位数组的长度不超过 1000，那么 `n` 绝对不会超过 2000，加 `1` 的原因是由于结点值是从 `1` 开始的。

开始表示每个结点都是一个单独的组，所谓的 Union Find 就是要让结点之间建立关联，比如若 `root[1] = 2`，就表示结点1和结点2是相连的，`root[2] = 3` 表示结点2和结点3是相连的，如果此时新加一条边 `[1, 3]` 的话，我们通过 `root[1]` 得到 `2`，再通过 `root[2]` 得到 `3`，说明结点1有另一条路径能到结点3，这样就说明环是存在的；如果没有这条路径，那么要将结点1和结点3关联起来，让 `root[1] = 3` 即可。

并查集的基础知识：

[并查集（Disjoint-set union）第1讲](https://youtu.be/YKE4Vd1ysPI)
[并查集（Disjoint-set union）第2讲](https://youtu.be/gpmOaSBcbYA)
[并查集（Disjoint-set union）第3讲](https://youtu.be/zos--xohLT0)
[花花酱 LeetCode 684. Redundant Connection](https://youtu.be/4hJ721ce010)

**思路：**

- 找到环，找到环里最后出现的一条边，把这条边删去
- 无向图找环，用并查集来判断是否有环
- 在合并之前，如果两个点已经在一个集合里了，说明当前边加完之后会形成一个环
- 从前往后枚举，最后出现环的位置就一定是最后一次出现的边
