# 210_Course Schedule II_课程表 II

## 解法：(拓扑排序) $O(n+m)$

1. 关于拓扑排序算法详见 [LeetCode 207_Course Schedule_课程表](https://leetcode.com/problems/course-schedule/)（拓扑排序）。

2. 拓扑排序时用的队列的进队顺序就是一个可行的输出方案。

**时间复杂度：**

- 假设 `n` 为点数，`m` 为边数，拓扑排序仅遍历所有的点和边一次，故总时间复杂度为 $O(n+m)$。

**空间复杂度：**

- 需要额外 $O(n+m)$ 的空间存储邻接表，点的入度，队列和答案。
