# 240_Search a 2D Matrix II_搜索二维矩阵 II (Medium)

## 解法一：逐行/逐列二分 $O(m * \log{n})$ 或 $O(n * \log{m})$

- 与 `（题解）74. 搜索二维矩阵` 不同，本题没有确保「每行的第一个整数大于前一行的最后一个整数」，因此我们无法采取「两次二分」的做法。
- 只能退而求之，遍历行/列，然后再对列/行进行二分。

**复杂度分析**
- 时间复杂度：$O(m * \log{n})$ 或 $O(n * \log{m})$
- 空间复杂度：$O(1)$

## 解法二：$BST$思路 单调性线性扫描（巧妙）$O(m + n)$

该做法则与 （题解）74. 搜索二维矩阵 的「解法二」完全一致。

我们可以将二维矩阵抽象成「以右上角为根的 $BST$」：

![BST思路](https://pic.leetcode-cn.com/1617066993-AyRIiF-image.png)

- 那么我们可以从根（右上角）开始搜索，如果当前的节点不等于目标值，可以按照树的搜索顺序进行：
  - 当前节点「大于」目标值，搜索当前节点的「左子树」，也就是当前矩阵位置的「左方格子」，即 `col--`
  - 当前节点「小于」目标值，搜索当前节点的「右子树」，也就是当前矩阵位置的「下方格子」，即 `row++`

- 关键在于起点的选取，从左下角或者右上角开始
- 从矩阵的右上角开始匹配，如果匹配到了，返回 $true$
- 如果值比 $target$ 大，说明这一列都比 $target$ 大，$col$ 往左移一行
- 如果值比 $target$ 小，则说明这一行都比 $target$ 小，$row$ 往下移一行

**复杂度分析：**
- 时间复杂度：$O(m + n)$
- 空间复杂度：$O(1)$

## （弃）解法三：四个方向二分压缩

时间复杂度：(二分) $O(k(logn+logm))$

初始化上下左右边界 `up`, `down`, `left`, `right`，保证 `target` 可能出现在此区域。

- 每次在 `up` 行中，二分求出新的 `right`；在 `down` 行中，二分求出新的 `left`；

- 接着在 `2` 求出的 `left` 列中，二分求出新的 `down`；在 `2` 求出的 `right` 列中，二分求出新的 `up`；

- 如果 `up == down && left == right`，则判断 `matrix[up][left] == target`。

注意，如果一轮迭代更新中，四个元素的值都没有变化，则说明那一片区域有多个 `target`，直接返回 `true`。


**时间复杂度**：

每次迭代时间复杂度为 `O(log⁡n+log⁡m)`，假设需要 `k` 次迭代，故时间复杂度为 `O(k(logn+logm))`。
最坏情况可能 `k=min(n,m)`，但平均情况下很难达到最坏情况。

**空间复杂度**：仅需要常数的额外空间。

## （弃）解法四：两个方向二分压缩

求出 `new_right`、`new_up`，从右上方开始不断将行和列进行二分求解，分治思维。


## （弃）解法五：暴力法 $O(m*n)$

**复杂度分析：**
- 时间复杂度：$O(m*n)$，因为我们在 $n×m$ 矩阵上操作，总的时间复杂度为矩阵的大小。
- 空间复杂度：$O(1)$，暴力法分配的额外空间不超过少量指针，因此内存占用是恒定的。
