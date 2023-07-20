# 40. Combination Sum II_组合总和 II

## 解法一：

题意：
这道题目和 [39.组合总和] 如下区别：

本题 `candidates` 中的每个数字在每个组合中只能使用一次。
本题数组 `candidates` 的元素是有重复的，而 [39.组合总和] 是无重复元素的数组 `candidates`
最后本题和 [39.组合总和] 要求一样，解集不能包含重复的组合。

都知道组合问题可以抽象为树形结构，那么“使用过”在这个树形结构上是有两个维度的，一个维度是同一**树枝上**使用过，一个维度是同一**树层上**使用过。没有理解这两个层面上的“使用过” 是造成大家没有彻底理解去重的根本原因。

我们是要同一树层上使用过，还是同一树枝上使用过呢？

回看一下题目，元素在同一个组合内是可以重复的，怎么重复都没事，但两个组合不能相同。

**所以我们要去重的是同一树层上的“使用过”，同一树枝上的都是一个组合里的元素，不用去重。**

**举例：**

`candidates = [1, 1, 2], target = 3`，（方便起见 `candidates` 已经排序了）

强调一下，树层去重的话，需要对数组排序！

选择过程树形结构如图所示：
![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20230310000918.png)

### 回溯三部曲

- 递归函数参数
与 [39.组合总和] 套路相同，此题还需要加一个`bool`型数组`used`，用来记录同一树枝上的元素是否使用过。
这个集合去重的重任就是`used`来完成的。
```cpp
vector<vector<int>> result; // 存放组合集合
vector<int> path;           // 符合条件的组合
void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {}
```

- 递归终止条件
与 [39.组合总和] 相同，终止条件为 `sum > target` 和 `sum == target`。
```cpp
if (sum > target) { // 这个条件其实可以省略
    return;
}
if (sum == target) {
    result.push_back(path);
    return;
}
```

- 单层搜索的逻辑
这里与 [39.组合总和] 最大的不同就是要去重了。
前面我们提到：要去重的是“同一树层上的使用过”，如何判断同一树层上元素（相同的元素）是否使用过了呢。

**如果 `candidates[i] == candidates[i - 1]` 并且 `used[i - 1] == false`，就说明：前一个树枝，使用了 `candidates[i - 1]`，也就是说同一树层使用过 `candidates[i - 1]`。**

此时$for$循环里就应该做 `continue` 的操作。
![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20230310000954.png)

在图中将`used`的变化用橘黄色标注上，可以看出在 `candidates[i] == candidates[i - 1]` 相同的情况下：

`used[i - 1] == true`，说明同一树枝`candidates[i - 1]`使用过
`used[i - 1] == false`，说明同一树层`candidates[i - 1]`使用过

可能有的录友想，为什么 `used[i - 1] == false` 就是同一树层呢，因为同一树层，`used[i - 1] == false` 才能表示，当前取的 `candidates[i]` 是从 `candidates[i - 1]` 回溯而来的。

而 `used[i - 1] == true`，说明是进入下一层递归，去下一个数，所以是树枝上，如图所示：
![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20221021163812.png)


时间复杂度: $O(n * 2^n)$
空间复杂度: $O(n)$


参考：https://programmercarl.com/0040.组合总和II.html#回溯三部曲