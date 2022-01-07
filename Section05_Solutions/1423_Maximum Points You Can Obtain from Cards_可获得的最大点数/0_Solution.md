# 1423_Maximum Points You Can Obtain from Cards_可获得的最大点数

## 解法一：滑动窗口

这题与第643题一个模型，是滑窗裸题。模板如下：

```cpp
int findMax(vector<int>& nums, int k) {
    int res = INT_MIN;
    for (int i = 0, j = 0, sum = 0; j < nums.size(); j++) {
        sum += nums[j];
        if (j - i + 1 > k) sum -= nums[i++];
        if (j >= k - 1) res = max(res, sum);
    }
    return res;
}
```

- 这题只需要转换下思路，$总量 - 滑窗中最小值 = 两边最大值$
- 从两边选择卡片，选择 $k$ 张，卡片的总数量为 $n$ 张，即有 $n - k$ 张不被选择。
- 所有卡边的总和 $tot$ 固定，要使选择的 $k$ 张的总和最大，反过来就是要让不被选择的 $n - k$ 张的总和最小。
- 可以使用滑动窗口来计算 $n - k$ 张卡片的最小总和 $min$，最终答案为 $tot - min$。
- 和 643.子数组最大平均数 I 代码很相似，因为是一套模板，所以说这道其实是道简单题，只是多了一个小学奥数难度的等式推导过程。

**复杂度分析**
- 时间复杂度：每个元素最多滑入和滑出窗口一次。复杂度为 $O(n)$
- 空间复杂度：$O(1)$
