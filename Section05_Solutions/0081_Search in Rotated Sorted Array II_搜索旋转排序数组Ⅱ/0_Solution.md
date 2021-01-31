# 81_Search in Rotated Sorted Array II_搜索旋转排序数组Ⅱ

## 解法一：二分查找

这题是 LeetCode 33_Search in Rotated Sorted Array_搜索旋转排序数组 的延伸。

区别是现在数组中允许出现重复数字。

解决方法就是当遇到下面情况时，将右边的与 $nums[0]$ 相同的数字删掉，这样就符合第33题的解题思路了。

![solve]()
