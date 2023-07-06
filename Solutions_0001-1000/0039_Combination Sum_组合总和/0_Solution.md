# 39. Combination Sum_组合总和

## 解法一：DFS＋回溯

1. 题目中的 **无限制重复被选取**，如果出现 $0$ 怎么办？题干提示 $1 <= candidates[i] <= 200$，所以不会出现 $0$
2. 本题和 `77.组合`，`216.组合总和III` 的区别是：本题没有数量要求，可以无限重复，但是有总和的限制，所以间接的也是有个数的限制。
3. 本题搜索的过程抽象成树形结构如下：
![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20201223170730367.png)
4. 注意图中叶子节点的返回条件，因为本题没有组合数量要求，仅仅是总和的限制，所以递归没有层数的限制，只要选取的元素总和超过 $target$，就返回！

### 回溯三部曲
1. 递归函数参数
- 这里依然是定义两个全局变量，二维数组 `res` 存放结果集，数组 `path` 存放符合条件的结果。（这两个变量可以作为函数参数传入）
- 首先是题目中给出的参数，集合`candidates`, 和目标值`target`。
- 此外我还定义了 $int$ 型的 `sum` 变量来统计单一结果 `path` 里的总和，其实这个 `sum` 也可以不用，用 `target` 做相应的减法就可以了，最后如何 `target==0` 就说明找到符合的结果了，但为了代码逻辑清晰，我依然用了 `sum`。
- 本题还需要 `startIndex` 来控制 $for$ 循环的起始位置，对于组合问题，什么时候需要 `startIndex` 呢？
```cpp
vector<vector<int>> result;
vector<int> path;
void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {}
```

2. 递归终止条件
- 从叶子节点可以清晰看到，终止只有两种情况，`sum` 大于 `target` 和`sum` 等于 `target`。
- `sum` 等于 `target` 的时候，需要收集结果。
```cpp
if (sum > target) {
    return;
}
if (sum == target) {
    result.push_back(path);
    return;
}
```

3. 单层搜索的逻辑

单层 $for$ 循环依然是从 $startIndex$ 开始，搜索 $candidates$ 集合。横向的搜索。
纵向的不用 `i+1` 了，因为可以重复取当前的数。

```cpp
for (int i = startIndex; i < candidates.size(); i++) {
    sum += candidates[i];
    path.push_back(candidates[i]);
    backtracking(candidates, target, sum, i); // 关键点:不用i+1了，表示可以重复读取当前的数
    sum -= candidates[i];   // 回溯
    path.pop_back();        // 回溯
}
```

## 解法二：剪枝

![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20201223170809182.png)

$for$ 循环剪枝代码如下：
```cpp
for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
```

时间复杂度: $O(n * 2^n)$，注意这只是复杂度的上界，因为剪枝的存在，真实的时间复杂度远小于此
空间复杂度: $O(target)$