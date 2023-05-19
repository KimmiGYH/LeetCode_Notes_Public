# 238_Product of Array Except Self_除自身以外数组的乘积

## 解法一：前缀积 (不开新空间)

**(前缀积)  $O(n)$**

[Youtube山景城一姐: [LeetCode]238. Product of Array Except Self](https://youtu.be/rpQhKorJRd8)

- 利用 `res` 数组当做临时存储空间，令 `res[i]` 为从 `nums[0] * nums[1] * ... * num[i - 1]`。
- 然后从数组末尾，用变量 `right` 记录末尾若干数字的乘积，每次更新 `res[i]` 即可得到答案。


- 从左往右，只存左半边的乘积：$res[i] = res[i - 1] * nums[i - 1]$
- 从右往左，只存右半边的乘积：$res[i] = res[i] * right$
  - 更新 `right`：$right = right * nums[i]$

**时间复杂度：**

只扫描数组两次，故时间复杂度为 $O(n)$。

**空间复杂度：**

除 `res` 数组之外只使用了若干变量，故空间复杂度为$O(1)$。

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        // 从左往右，只存左半边的乘积：res[i] = res[i-1] * nums[i-1];
        for (int i = 1; i < n; ++i)
            res[i] = res[i - 1] * nums[i - 1];
        // 从右往左，只存右半边的乘积： res[i] = res[i] * right;
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};
```

## 解法二：前后缀分解（跳过不看）

算法分析：

- 1. 用两个数组维护前缀积和后缀积，即 `left[i]` 维护的是 `[0,i]` 的前缀积，`right[i]` 维护的是 `[i,n - 1]` 的后缀积
- 2. 若计算 `nums[i]` 之外其余各元素的乘积，等价于计算 `left[i - 1] * right[i + 1]`

时间复杂度： $O(n)$

空间复杂度： $O(n)$