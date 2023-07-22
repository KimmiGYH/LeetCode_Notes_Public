# 46. Permutations_全排列

## 解法一：(回溯) $O(n×n!)$

- 我们从前往后，一位一位枚举，每次选择一个没有被使用过的数。
- 选好之后，将该数的状态改成**已被使用**，同时将该数记录在相应位置上，然后递归。
- 递归返回时，不要忘记将该数的状态改成**未被使用**，并将该数从相应位置上删除。


以[1,2,3]为例，抽象成树形结构如下：
![图解](https://code-thinking-1253855093.file.myqcloud.com/pics/20211027181706.png)

## 回溯三部曲

- 递归函数参数

可以看出元素1在[1,2]中已经使用过了，但是在[2,1]中还要在使用一次1，所以处理排列问题就不用使用`startIndex`了。

但排列问题需要一个used数组，标记已经选择的元素，如图橘黄色部分所示。

```cpp
vector<vector<int>> result;
vector<int> path;
void backtracking (vector<int>& nums, vector<bool>& used)
```

- 递归终止条件

当收集元素的数组`path`的大小达到和`nums`数组一样大的时候，说明找到了一个全排列，也表示到达了叶子节点。

- 单层搜索的逻辑

`used`数组记录`path`里都有哪些元素使用了，一个排列里一个元素只能使用一次。

```cpp
for (int i = 0; i < nums.size(); i++) {
    if (used[i] == true) continue; // path里已经收录的元素，直接跳过
    used[i] = true;
    path.push_back(nums[i]);
    backtracking(nums, used);
    path.pop_back();
    used[i] = false;
}
```
**复杂度分析：**
- 时间复杂度: $O(n!)$
- 空间复杂度: $O(n)$

## 总结
大家此时可以感受出排列问题的不同：

- 每层都是从`0`开始搜索而不是`startIndex`
- 需要`used`数组记录path里都放了哪些元素了

