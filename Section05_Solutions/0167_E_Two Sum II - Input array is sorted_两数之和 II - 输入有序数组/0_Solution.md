# 167_Two Sum II - Input array is sorted_两数之和 II - 输入有序数组

## 解法一：双指针 Two Pointers $O(n)$

双指针算法：

只需要两个指针，一个指向开头，一个指向末尾，然后向中间遍历，如果指向的两个数相加正好等于target的话，直接返回两个指针的位置即可，若小于target，左指针右移一位，若大于target，右指针左移一位，以此类推直至两个指针相遇停止。

```cpp
numbers[i] + numbers[j] = target; // numbers[j]一定是最大的那个数

numbers[i] + numbers[j] > target  j--;    // j 指针从后往前走

if (i < j && numbers[i] + numbers[j] == target) return {i+1, j+1};

// i < j 是为了使元素不被重复使用
```


## 解法二：二分 $O(nlogn)$

二分没有双指针来得有效率。

可以用二分法来搜索，因为一定有解，而且数组是有序的，那么第一个数字肯定要小于目标值`target`，那么我们每次用二分法来搜索 `target - numbers[i]` 即可。
