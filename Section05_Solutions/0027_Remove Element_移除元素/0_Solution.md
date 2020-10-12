# 27. Remove Element 移除元素 (Easy)



## 解法1：双指针法

快指针遍历数组全部元素；慢指针只在满足条件时移动指针。

```c++
if (nums[i] != val)
	nums[k++] = nums[i];
```

当元素 `nums[i]`不为 `val`，将元素 `nums[i]` 放到 慢指针 `k` 的位置。

返回 `k`，此时 `k` 便是新数组的长度 `len`。

