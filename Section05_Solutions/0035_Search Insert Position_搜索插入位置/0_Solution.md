# 35_Search Insert Position_搜索插入位置 (Easy)

## 解法一：二分查找

- 从前往后找到第一个大于等于 $target$ 的位置，性质是 $nums[mid] >= target$
- 区间更新为 $r = mid$, $left = mid + 1$
- 注意 $r$ 的取值可以取 $nums.size()$，因为最后一个位置也是可以插入的，比如在以下情况：

    ```cpp
    [1,3,5,6] 7
    // 这里 7 是插到数组最后一个位置
    ```
