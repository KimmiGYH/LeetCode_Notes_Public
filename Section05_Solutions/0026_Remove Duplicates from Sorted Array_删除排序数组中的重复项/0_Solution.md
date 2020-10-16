# 26. Remove Duplicates from Sorted Array

## 方法一：双指针法，时间复杂度 O(n)

此题使用双指针法，O(n)的时间复杂度。

注意题目中：不要使用额外的数组空间，必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

![image](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section03_Solutions/0026_Remove%20Duplicates%20from%20Sorted%20Array/solve1.png)

判断 `nums[k]` 是否和 `nums[i]` 不同，如果不同，那么 `nums[++k] = nums[i]`。


## 写法2

双指针算法，两个指针，指针`i`进行扫描，指针`k`保存元素。
得到的`k`值便是新数组的长度。