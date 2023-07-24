# 51. N-Queens_N 皇后(Hard)

## 解法一：(按行枚举) $O(n!)$

对角线 `dg[u+i]`，反对角线 `udg[n−u+i]` 中的下标 `u + i` 和 `u - i + (n - 1)` 表示的是截距。

下面的 `(x, y)` 相当于`(u, i)`：

（1）反对角线 `y = x + b`, 截距 `b = y − x`，因为我们要把 `b` 当做数组下标，所以 `b` 不能是负的，所以我们 `+ (n - 1)`，保证是结果是正的
（2）而对角线 `y = −x + b`, 截距是 `b = y + x`，这里截距一定是正的，所以不需要加偏移量。

## 解法二：DFS＋回溯

- 递归函数参数
定义全局变量二维数组`res`来记录最终结果。
参数 `n` 是棋盘的大小，然后用 `row` 来记录当前遍历到棋盘的第几层了。
```cpp
vector<vector<string>> res;
void backtracking(int n, int row, vector<string>& path) {}
```

- 递归终止条件
当递归到棋盘最底层（也就是叶子节点）的时候，就可以收集结果并返回了。
```cpp
if (row == n) {
    result.push_back(path);
    return;
}
```

- 单层搜索的逻辑
```cpp
for (int col = 0; col < n; col++) {
    if (isValid()) {   // 验证合法就可以放
        path[row][col] = 'Q';           // 放置皇后
        backtracking(row + 1, n);
        path[row][col] = '.';           // 回溯，撤销皇后
    }
}
```

- 验证棋盘是否合法
按照如下标准去重：
1. 不能同行
2. 不能同列
3. 不能同斜线 （45度和135度角）

```cpp
for (int i = 0; i < n; i++) {
    if (!col[i] && !dg[i + r] && !udg[i - r + n]) {
        col[i] = dg[i + r] = udg[i - r + n] = true;
        path[r][i] = 'Q';
        backtracking(r + 1, n);
        col[i] = dg[i + r] = udg[i - r + n] = false;
        path[r][i] = '.';
    }
}
```

45°对角线和 135°对角线总共有 $2n - 1$ 根。
如果枚举某行的列，`i` 为枚举的值：
- 绿色的45°对角线函数为 $y = -x + k$，截距为 $k = y + x$；`dg[i + r]`
- 红色的135°对角线函数为 $y = x + k$，截距为 $k = y - x$，可能出现负数，需要加上偏移量 $n$；`udg[i - r + n]`
