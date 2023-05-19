# 216. Combination Sum III_组合总和 III



## 解法一：DFS

##### (DFS) $O(C_{9}^{k} * k)$

暴力搜索出所有从 `9` 个数中选 `k` 个的方案，记录所有和等于 `n` 的方案。

为了避免重复计数，比如 `{1, 2, 3}` 和 `{1, 3, 2}` 是同一个集合，我们对集合中的数定序，每次枚举时，要保证同一方案中的数严格递增，即如果上一个选的数是 `x`，那我们从 `x+1` 开始枚举当前数。

##### 时间复杂度分析

从 `9` 个数中选 `k` 个总共有 $O(C_{9}^{k})$ 个方案，将每个方案记录下来需要 $O(k)$ 的时间，所以时间复杂度是

$O(C_{9}^{k} * k)$。


![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0216_Combination%20Sum%20III_%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C%20III/solve.png)



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

Space complexity: $O(k + k * # of ans)$

![Bit](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0216_Combination%20Sum%20III_%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C%20III/Bit.png)