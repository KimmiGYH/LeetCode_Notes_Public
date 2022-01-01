# 45. Jump Game II_跳跃游戏 II (DP+Greedy) (Hard)

### 算法一：动态规划

这道题一看就是**有限集合的最优化问题**，所以想到用动态规划，定义 $f[i]$ 为跳到点 `i` 需要的最小步数。

时间复杂度：$O(n^{2})$，超时。

```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0x3f3f3f3f);
        for (int i = 0; i < n; i++) {
            if (!i) f[i] = 0; // 处理边界
            else {
                for (int j = 0; j < i; j++) { 
                    if (j + nums[j] >= i) { // 只要前面的点能跳到i点就更新最小值
                        f[i] = min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[n - 1];
    }
};
```

很遗憾动态规划超时了，所以想办法优化。

### 算法二：动态规划+贪心

我们会发现 $f[i]$ 是具有单调性的，也就是 $f[i + 1] >= f[i]$。

**用反证法：**

1. 假设 $f[i + 1] < f[i]$，
2. 不妨设是从 $k  (k <= i)$ 点跳到 $i + 1$，即：$k + nums[k] >= i + 1$，
3. 那么 $k + nums[k]$ 也必然大于 $i$，此时：$f[i + 1] = f[i]$ 了。
4. 然而如果 $nums$ 数组每一项都为 $1$，则：$f[i + 1] > f[i]$，
5. 综上：$f[i + 1] >= f[i]$，与假设矛盾。

- 因此 $f[i]$ 就变成了 `0 1...1 2...2 3...3 ......`

- 在动态规划时瓶颈就在于更新每个点的最小值时需要遍历所有能跳到 $i$ 的点，而有了单调性以后就可以用第一个能跳到 $i$ 的点更新了，这里无论是取哪一个点跳到 $i$，其最终的结果是一样的，
- 但是取第一个点和取最后一个点所需要的步数可能不相同，所以尽量选择靠前的点，这样步数就可能会减少，**贪心**的思想。

**时间复杂度：**

- 数组的每个元素最多被遍历两次，故时间复杂度为 $O(n)$。

**空间复杂度：**

- 需要 $O(n)$ 的额外空间存储数组 $f$。

```C++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (!i) f[i] = 0;
            else {
                while (j + nums[j] < i) j++; // 找到第一个能跳到 i 的点 j
                f[i] = f[j] + 1; // 根据 f[j] 更新 f[i]
            }
        }
        return f[n - 1];
    }
};
```

### 过程步骤视频
https://leetcode-cn.com/problems/jump-game-ii/solution/dong-tai-gui-hua-jie-fa-by-alchemist-5r/

