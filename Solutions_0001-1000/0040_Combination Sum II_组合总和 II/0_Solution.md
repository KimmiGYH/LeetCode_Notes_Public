# 40. Combination Sum II_组合总和 II



## 解法一：使用`set`来去重

更新了数据，所以此方法通不过了。不过思路可以的。

```
[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
30
```

```c++
        set<vector<int>> res;
```

## 解法二：使用`vector`

[花花酱 LeetCode 40. Combination Sum II](https://youtu.be/RSatA4uVBDQ?t=549)



记得要加判重的条件：(和 [47. Permutation II](https://github.com/KimmiGYH/LeetCode_Notes_Public/blob/master/Section05_Solutions/0047_Permutations%20II_%E5%85%A8%E6%8E%92%E5%88%97%20II/0_Solution.md) 里的条件有点像但又有区别)


**同一深度时，不允许有相同的数：**

比如有两个 `1`，加上判重的条件后，`i > s` 表示对于当前这层递归循环只能使用其中一个元素，另一个重复元素可以在下层循环使用。

```c++
if (i > s && candidates[i] == candidates[i - 1]) continue;
```

得到结果：

```
1 1 6 
1 2 5 
1 7 
2 6
```

如果判重条件写成：(参考力扣47题全排列II)

```c++
if (i > 0 && candidates[i] == candidates[i - 1]) continue;
```

则结果中不会包含重复的元素，哪怕本身在 candidates 中有的重复元素。

得到结果：

```
1 2 5 
1 7 
2 6 
```

