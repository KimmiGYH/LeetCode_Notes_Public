# 二分边界详细总结



## 二分查找模板



### 一、查找精确值

从一个有序数组中找到一个符合要求的精确值（如猜数游戏）。如查找值为 `target` 的元素下标，不存在返回 `-1`。

这里 `left` 和 `right` 代表的是数组下标，所有没有必要改写成 `mid = left + (right - left)/2`;
因为当代表数组下标的时候，在数值越界之前，内存可能就已经越界了；
如果 `left` 和 `right` 代表的是一个整数，就有必要使用后面一种写法防止整数越界。

```c++
// 这里是left <= right。
int left = 1, right = n;
while(left <= right)
{
    int mid = (left + right) / 2;
    if(A[mid] == target)
        return mid;
    else if(A[mid] > target)
        right = mid - 1;
    else
        left = mid + 1;
}
return -1;
```

**或者写成这样：**

```c++
int binary_search(int[] nums, int target) {
    int left = 0, right = nums.length - 1; 
    while(left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] == target) {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}
```



### 二、查找大于等于 / 大于 `target` 的第一个元素

这种通常题目描述为满足某种情况的**最小的元素**。

```c++
int left = 1, right = n;
while(left < right)
{
    int mid = (left + right) / 2;
    if(A[mid] >= target) // 如果要求大于等于可以加上等于，也可以是 check(A[mid])
        right = mid;
    else
        left = mid + 1;
}
```

**或者写成这样：**

```c++
int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}
```



### 三、查找小于等于/小于 `target` 的最后一个元素

```c++
int left = 1, right = n;
while(left < right)
{
    int mid = (left + right + 1) / 2;
    if(A[mid] <= target)
        left = mid;
    else
        right = mid - 1;
}
```

**或者写成这样：**

```c++
int right_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + right >> 1;
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}
```



### 四、总结

- 查找精确值，循环条件是小于等于；查找满足情况的最大最小值，循环条件是小于。
- 查找满足条件的最大数，`mid = (right + left + 1) / 2`；查找满足条件的最小数，`mid = (right + left) / 2`。
- 检查越界：
  - 查找第一个大于等于 `target` 的值，检查 `left` 是不是越界，即是否 `left > nums.size() - 1`？
  - 查找最后一个小于等于 `target` 的值，检查 `right` 是否越界，即是否 `right < 0`？



【参考文章】

[AcWing: T-SHLoRk：二分边界详细总结](https://www.acwing.com/blog/content/307/)

[GitHub: labuladong：二分查找详解](https://github.com/labuladong/fucking-algorithm/blob/master/%E7%AE%97%E6%B3%95%E6%80%9D%E7%BB%B4%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE%E8%AF%A6%E8%A7%A3.md)



