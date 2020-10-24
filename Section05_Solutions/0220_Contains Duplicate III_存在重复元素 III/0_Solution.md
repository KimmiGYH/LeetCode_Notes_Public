# 220. Contains Duplicate III_存在重复元素 III (Meidum)

## 解法一：

`|ai - aj| ≤ t`

和 `ai` 的距离不超过 `k`是一个滑动窗口 Sliding window，要看在长度为 `k` 的窗口内是否存在一个数和`ai` 的差不超过 `t`。

即在窗口内寻找一个和 `ai` 最接近的数。



## 解法二：

bobo老师

在 219题的基础上改写的。



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0220_Contains%20Duplicate%20III_%E5%AD%98%E5%9C%A8%E9%87%8D%E5%A4%8D%E5%85%83%E7%B4%A0%20III/solve.png)

## `set`中的lower_bound` 和 `upper_bound的使用：


　　iterator lower\_bound( const key\_type &key ): 返回一个迭代器，指向**键值>= key**的第一个元素。

　　iterator upper\_bound( const key\_type &key ): 返回一个迭代器，指向**键值> key**的第一个元素。












