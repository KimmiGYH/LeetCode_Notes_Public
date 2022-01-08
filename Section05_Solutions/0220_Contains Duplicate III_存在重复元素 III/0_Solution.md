# 220. Contains Duplicate III_存在重复元素 III (Meidum)

## 解法一：在滑动窗口内寻找与 $x$ 最接近的数

- $|a_{i} - a_{j}| \le t$
- 和 $a_{i}$ 的距离不超过 $k$ 是一个滑动窗口
- 要看在长度为 $k$ 的窗口内是否存在一个数和$a_{i}$ 的差不超过 $t$，即在窗口内寻找一个和 $a_{i}$ 最接近的数。

```cpp
*lower_bound(nums[i]) - nums[i] <= t
--it;
nums[i] - *lower_bound(nums[i]) <= t
即
nums[i] - t <= *lower_bound(nums[i]) <= nums[i] + t

等价于

lower_bound(nums[i] - t) <= nums[i] + t
```
## 解法二：$set$ 和 `lower_bound` $O(nlog{n})$

bobo老师

在 219题的基础上改写的。


### `set` 中的 `lower_bound` 和 `upper_bound` 的使用：
- `iterator lower_bound( const key_type &key )`: 返回一个迭代器，指向 **`键值>= key`** 的第一个元素。
- `iterator upper_bound( const key_type &key )`: 返回一个迭代器，指向 **`键值> key`** 的第一个元素。

算法思路：
- $abs(v-x) \le t$ 表示所要找的元素的范围是在 $v-t$ 到 $v+t$ 之间的，换句话说，如果将这个区间内的所有元素存进一个查找表中，就看有没有某一个元素 $\ge v-t$ 且 $\le v+t$ 的呢？
- 如果查找表具有顺序性，只需让 `lower_bound(v-t) <= v+t`
- 每当有一个新的 $nums[i]$ 来的时候，此时要确保在查找表中，`record.lower_bound(nums[i] - t)` 即 $\ge nums[i] - t$ 的最小的值是存在的；
- **同时**，这个取值 `record.lower_bound(nums[i] - t)` 要  $\le nums[i] + t$


**复杂度分析**
- 时间复杂度：$O(nlog{n})$
  - 由于 $set$ 是二叉树实现的查找表，所以每个和 $set$ 相关的操作变成了 $O(log n)$
  - 所以整体复杂度变成了 $O(nlog{n})$
- 空间复杂度：$O(k)$
  - 因为在查找表中最多存储 $k+1$ 个元素






