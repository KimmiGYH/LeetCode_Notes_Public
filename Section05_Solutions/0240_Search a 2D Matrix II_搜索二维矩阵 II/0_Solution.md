# 240_Search a 2D Matrix II_搜索二维矩阵 II (Medium)

## 解法一：暴力法

时间复杂度：`O(mn)`，因为我们在 `n×m` 矩阵上操作，总的时间复杂度为矩阵的大小。
空间复杂度：`O(1)`，暴力法分配的额外空间不超过少量指针，因此内存占用是恒定的。

## 解法二：搜索空间的缩减（巧妙）

- 关键在于起点的选取，从左下角或者右上角开始
- 从矩阵的右上角开始匹配，如果匹配到了，返回 `true`
- 如果值比 `target` 大，说明这一列都比 `target` 大，`column` 往左移一行
- 如果值比 `target` 小，则说明这一行都比 `target` 小，`row` 往下移一行

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0240_Search%20a%202D%20Matrix%20II_%E6%90%9C%E7%B4%A2%E4%BA%8C%E7%BB%B4%E7%9F%A9%E9%98%B5%20II/solve.png)
