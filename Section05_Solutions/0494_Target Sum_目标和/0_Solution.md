# 494_Target Sum_目标和 (Medium)



**核心是01背包问题**



## 解法一：二维DP



可以使用迭代的方法来解，使用一个 `dp` 数组，其中 `dp[i][j]` 表示到第 `i-1` 个数字且和为 `j` 的**情况总数**。

[花花酱 LeetCode 494. Target Sum 上](https://youtu.be/r6Wz4W1TbuI)

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (auto &a : dp[i]) {
                int sum = a.first, cnt = a.second;
                dp[i + 1][sum + nums[i]] += cnt;
                dp[i + 1][sum - nums[i]] += cnt;
            }
        }
        return dp[n][S];
    }
};
```



## 解法二：一维DP



也可以对上面的方法进行空间上的优化，只用一个 `HashMap`，而不是用一个数组的哈希表，在遍历数组中的每一个数字时，新建一个 `HashMap`，在遍历原 `HashMap` 中的项时更新这个新建的 `HashMap`，最后把新建的 `HashMap` 整个赋值为原 `HashMap`。



```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> hash;
            for (auto a : dp) {
                int sum = a.first, cnt = a.second;
                hash[sum + num] += cnt;
                hash[sum - num] +=cnt;
            }
            dp = hash;
        }
        return dp[S];
    }
};
```



