# 215_Kth Largest Element in an Array_数组中的第K个最大元素

## 解法一：快速选择算法

经典题：找出数组中的第 `k` 个最小元素 [786.第k个数](https://www.acwing.com/activity/content/code/content/537801/)

- 写法一：现在要求数组中的第 `k` 个最大元素，只需要将符号要翻转一下。
- 写法二：或者保持原模板不变，只要将 $k$ 变化一下，比如要求第 $k$ 大的数，其实就是求第$nums.size() - k + 1$ 小的数。
