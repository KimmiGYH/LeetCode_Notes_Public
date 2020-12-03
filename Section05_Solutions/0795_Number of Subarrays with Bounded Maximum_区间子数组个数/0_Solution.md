# 795. Number of Subarrays with Bounded Maximum_区间子数组个数 (Medium)



## 解法一：数学(?)



这种方法是用一个子函数来算出最大值在 `[-∞, x]` 范围内的子数组的个数，而这种区间只需要一个循环就够了，为啥呢？

我们来看数组`[2, 1, 4, 3]` 的最大值在 `[-∞, 4]` 范围内的子数组的个数。

当遍历到 `2` 时，只有一个子数组 `[2]`，

遍历到 `1` 时，有三个子数组，`[2], [1], [2,1]`。

当遍历到 `4` 时，有六个子数组，`[2], [1], [4], [2,1], [1,4], [2,1,4]`。

当遍历到 `3` 时，有十个子数组。

其实如果长度为 `n` 的数组的最大值在范围 `[-∞, x]` 内的话，其所有子数组都是符合题意的，而长度为 `n` 的数组共有 `n(n+1)/2` 个子数组，刚好是**等差数列的求和公式**。所以我们在遍历数组的时候，

如果当前数组小于等于 `x`，则 `cur` 自增 `1`，然后将 `cur` 加到结果 `res` 中；

如果大于 `x`，则 `cur` 重置为0。

这样我们可以正确求出最大值在 `[-∞, x]` 范围内的子数组的个数。而要求最大值在 `[L, R]` 范围内的子数组的个数，只需要用最大值在 `[-∞, R]` 范围内的子数组的个数，减去最大值在 `[-∞, L-1]` 范围内的子数组的个数即可。



```c++
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        return count(A, R) - count(A, L - 1);
    }

    int count (vector<int>& A, int bound) {
        int res = 0, cur = 0;
        for (int x : A) {
            cur = (x <= bound) ? (++cur) : 0;
            res += cur;
        }
        return res;
    }
};
```



## 解法二：动态规划

星哥的解释：

- 如果当前这个数小于 `L`，那到这个数为止符合规则的子序列，就和 `dp[i-1]` 一样；

- 如果当前数字在 `L` 和 `R` 之间，那到包含这个数字能组成符合规则的子序列就是当前坐标减去上一个大于 `R` 的位置；

- 要是当前数字大于 `R` 了，那包含这个数字就没法组成符合规则的子序列，那 `dp[i]` 就等于 `0`，并且要更新一下 `pre`，为下一次发现在 `L` 和 `R` 之间的数字做准备

```c++
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0, dp = 0;
        int pre = -1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] < L && i > 0)
                res += dp;
            if (L <= A[i] && A[i] <= R) {
                dp = i - pre;
                res += dp;
            }
            if (A[i] > R) {
                dp = 0;
                pre = i;
            }
        }
        return res;
    }
};
```

