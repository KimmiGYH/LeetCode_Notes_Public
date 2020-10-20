# 167_Two Sum II - Input array is sorted_两数之和 II - 输入有序数组

## 解法一：双指针 Two Pointers
双指针算法

```
numbers[i] + numbers[j] = target; // numbers[j]一定是最大的那个数

numbers[i] + numbers[j] > target  j--;    // j 指针从后往前走

if (i < j && nummbers[i] + numbers[j] == target) return (i+1, j+1);

// i < j 是为了使元素不被重复使用
```