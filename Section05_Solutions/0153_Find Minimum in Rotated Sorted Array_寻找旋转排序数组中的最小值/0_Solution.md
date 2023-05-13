# 153_Find Minimum in Rotated Sorted Array_寻找旋转排序数组中的最小值

## (y总)解法一：闭区间

- 数组中最小值前面的数 $nums[i]$ 都满足：$nums[i] ≥ nums[0]$，其中 $nums[n−1]$ 是数组最后一个元素；而数组中最小值后面的数（包括最小值）都不满足这个条件。
- 所以我们可以二分出最小值的位置。

- 另外，不要忘记处理数组完全单调的特殊情况。如果只有一段的话，那么 $nums.back() > nums[0]$。

**时间复杂度分析**：

- 二分查找，所以时间复杂度是 $O(logn)$。

## (0x3f)解法二：开区间

- 这题给你一个数组，它可能是一个递增的数组，也有可能是两段的递增数组，且第一个数大于最后一个数。那么怎么用 $O(logn)$ 的时间找到数组的最小值呢？

- 我们需要一个判定方式来判断二分的位置是在最小值的左侧还是右侧？我们可以和最后一个数比大小，由于最小值一定在数组中，那么最后一个数，要么是最小值，要么在最小值右侧，所以可以在 $[0, n-2]$ 中二分。

- (1) 如果是小于最后一个数，那么有两种情况，① 它在同一段递增数组中，② 或者在两段递增数组中的第二段。那无论是哪种情况，这个元素要么是最小值，要么在最小值右侧。

- (2) 另外一种情况就是大于最后一个数，那么第①种情况就不可能了。分两段的情况中，说明它一定在最小值左侧。


## 讨论 1：
【问】：若是左闭右闭区间的话，右边界到底取 `n-1` 还是 `n-2`？
【答】：闭区间右边界取 `n-2`，因为 `nums[n-1]` 这个值要么是最小值，要么在答案的右侧，所以无需二分，可以提前判断边界元素，这样可以简化代码。

## 讨论 2：
【问】：该和第一个元素比较，还是和最后一个元素比较？
【答】：都可以。

## 写法一：和最后一个元素比较，左闭右闭区间
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        // [0, n-2]
        int l = 0, r = nums.size() - 2;
        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums.back()) r = mid - 1;
            else l = mid + 1;
        }
        return nums[l];
    }
};
```
当 `l = r + 1` 时停止循环，`nums[l]` 即 `nums[n-1]` 可以取到最后一个元素为答案的情况。


## 写法二：和最后一个元素比较，左开右开区间
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        // (-1, n-1)
        int l = -1, r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums.back()) r = mid;
            else l = mid;
        }
        return nums[r];
    }
};
```
对于双开区间二分模板中二分区间 `(-1, n)` 即 `int l = -1, r = n`，当 `l + 1 = r` 时，即当 `l = n-1` 或 `r = -1` 时，需要 `return -1`。

把二分区间定义为 `(-1, n-1)`时，当二分区间找不到答案，那么返回的最后一个元素 `nums[r]` 就是答案。


## 写法三：和最后一个元素比较，左闭右开区间
```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        // [0, n-2]
        // [0, n-1) 左闭右开区间写法
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums.back()) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};
```
如果强行把区间定义为 `[0, n-1]` 或 `[0, n)`，这题的代码会出错：
```
输入：nums = [3,4,5,1,2]
错误输出：-1094795586
预期结果：1
```

❓**我的问题**：如何改写能使程序跑通？要求：1) 用左闭右开区间 `[0, n)`，且和最后一个元素比较。


```cpp
class Solution { //ChatGPT给到的修改后的代码还是错误！❌：
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size(); // 修改 r 的初始值
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            else if (mid == nums.size() - 1) return nums.back();
            else if (nums[mid] < nums.back()) r = mid;
            else l = mid + 1;
        }
        return nums[0];
    }
};
```

## 写法四：和第一个元素比较，左闭右闭区间

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[r] > nums[l])return nums[0];
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};
```