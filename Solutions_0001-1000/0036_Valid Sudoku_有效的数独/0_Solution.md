# 36_Valid Sudoku_有效的数独

![sudoku](https://pic.leetcode-cn.com/2b141392e2a1811d0e8dfdf6279b1352e59fad0b3961908c6ff9412b6a7e7ccf-image.png)

## 解法一：数组遍历

**思路**：一个简单的解决方案是遍历该 9 x 9 数独三次，以确保：

- 行中没有重复的数字。
- 列中没有重复的数字。
- 3 x 3 子数独内没有重复的数字。

注意，在判断列的时候，可以有两种写法：

```cpp
// v1
for (int i = 0; i < 9; i++) {
    memset(check, 0, sizeof check);
    for (int j = 0; j < 9; j++) {
        if (board[j][i] != '.') {
            int t = board[j][i] - '1'; // board[j][i]，将i, j交换
            if (check[t]) return false;
            check[t] = true;
        }
    }
}
```

```cpp
// v2（觉得更好理解）
for (int j = 0; j < 9; j++) {           // for循环里先写j，并保持 board[i][j] 的顺序
    memset(check, 0, sizeof check);
    for (int i = 0; i < 9; i++) {
        if (board[i][j] != '.') {
            int t = board[i][j] - '1';
            if (check[t]) return false;
            check[t] = true;
        }
    }
}
```


## 解法二：位运算判重

如何枚举子数独？

```cpp
 box_index = (row / 3) * 3 + columns / 3
```

- 分别使用一个整型数组记录每行、每列和每个九宫格内数字的存在情况。
- 位运算可以极大的简化判断，提高效率，具体看代码。

```cpp
(row[i] & (1 << num)) ||
(col[j] & (1 << num)) ||
(squ[(i / 3) * 3 + (j / 3)] & (1 << num))
```

**复杂度分析：**

- 时间复杂度：$O(1)$，因为我们只对 $81$ 个单元格进行了一次迭代。
- 空间复杂度：$O(1)$。
