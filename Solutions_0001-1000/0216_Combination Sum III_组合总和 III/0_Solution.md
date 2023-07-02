# 216. Combination Sum III_组合总和 III



## 解法一：DFS

##### (DFS) $O(C_{9}^{k} * k)$

暴力搜索出所有从 `9` 个数中选 `k` 个的方案，记录所有和等于 `n` 的方案。

这道题是在题 #77 的基础上，增加了一个条件 “总和等于`n`”，以及多了一个剪枝优化。

1. 已选元素总和如果已经大于 `n`（图中数值为4）了，那么往后遍历就没有意义了，直接剪掉。
那么剪枝的地方可以放在递归函数开始的地方，剪枝代码如下：

    ```cpp
    if (sum > targetSum) { // 剪枝操作
        return;
    }
    ```
2. 和回溯算法：组合问题再剪剪枝 (opens new window) 一样，for循环的范围也可以剪枝，`i <= 9 - (k - path.size()) + 1` 就可以了。

##### 时间复杂度分析

- 从 `9` 个数中选 `k` 个总共有 $O(C_{9}^{k})$ 个方案，将每个方案记录下来需要 $O(k)$ 的时间，所以时间复杂度是 $O(C_{9}^{k} * k)$。



## 解法二：位运算（二进制映射）

[花花酱 LeetCode 216. Combination Sum III](https://youtu.be/UwdX19UvoCI?t=427)

```c++
[0,1,2]
//可以让每一位表示这个数选不选，由此可以用二进制数来表示选择的方案
//2 1 0
  0 0 0
  0 0 1
  0 1 0
  0 1 1
  1 0 0
  1 0 1
  1 1 0
  1 1 1
```

```c++
// use 9 bit binary string to represent a combination
000000000	->	[]
000000001	->	[1]
...
000100011	->	[6,2,1]
...
111111110	->	[9,8,7,6,5,4,3,2]
111111111	->	[9,8,7,6,5,4,3,2,1]
```

[组合数求和公式：组合数求和公式](https://www.cnblogs.com/1024th/p/10623541.html)

1. if `i-th` bit is `1`, then number `(i+1)` is used
2. total # of 1s should be `k`



Time complexity: $O(2^m) = O(2^9)$

Space complexity: $O(k + k * number\ of\ ans)$
