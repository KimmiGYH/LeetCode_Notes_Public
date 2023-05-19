# 199. Binary Tree Right Side View_二叉树的右视图 (Medium)



## 算法一：BFS



### 写法一：把每层最后一个元素记录下来



### 写法二：将 right 和 left 交换

将 `right` 与 `left` 交换，记录每层队列 `front` 的数，即最右侧的数。



## 算法二：DFS

- 在 pre-order 的基础上，将 `right` 与 `left` 顺序交换，按照 「根 -> 右 -> 左」 的顺序访问，就可以保证每层都是最先访问最右侧的节点。

- 遍历的结果：

  | root | depth |
  | ---- | ----- |
  | 1    | 0     |
  | 2    | 1     |
  | 4    | 2     |
  | 5    | 2     |
  | 2    | 1     |

- `while(res.size() <= depth)`，由于一开始 `depth` 为 `0`，`res`数组为空，此时将 `root` 的值加入 `res` 中。
  
- 示例中的树最多只有三层，那么每层取最右侧的数，不够的再看该层左侧的数。