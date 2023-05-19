# [239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/) (Hard)

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return *the max sliding window*.

 

**Example 1:**

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]
```

**Example 3:**

```
Input: nums = [1,-1], k = 1
Output: [1,-1]
```

**Example 4:**

```
Input: nums = [9,11], k = 2
Output: [11]
```

**Example 5:**

```
Input: nums = [4,-2], k = 2
Output: [4]
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`



**Hint 1**

How about using a data structure such as `deque` (double-ended queue)?

提示用双端队列 `deque` 来做。

**Hint 2**

The queue size need not be the same as the window’s size.

**Hint 3**

Remove redundant elements and the queue should store only elements that need to be considered.

提示我们窗口中只留下有用的值，没用的全部移除掉。



# [239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

难度困难

给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

**示例 1：**

```
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**示例 2：**

```
输入：nums = [1], k = 1
输出：[1]
```

**示例 3：**

```
输入：nums = [1,-1], k = 1
输出：[1,-1]
```

**示例 4：**

```
输入：nums = [9,11], k = 2
输出：[11]
```

**示例 5：**

```
输入：nums = [4,-2], k = 2
输出：[4]
```

 

**提示：**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

