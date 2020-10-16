# 80. Remove Duplicates from Sorted Array II (Medium)

## 解法一：双指针法

两个指针, 一个遍历整个数组，另一个`k`保存元素。

对于这类保留`m`个相同元素的问题，`m`是题目中给定的，解题模板：

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int k = 0;
        for (auto x : nums)
            if (k < m || nums[k-m] != x)
                nums[k++] = x;

        return k;
    }
};
```
