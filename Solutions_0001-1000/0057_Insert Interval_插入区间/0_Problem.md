# [57. Insert Interval](https://leetcode.com/problems/insert-interval/) (Medium)

Given a set of *non-overlapping* intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

 

**Example 1:**

```
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Example 2:**

```
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

**Example 3:**

```
Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
```

**Example 4:**

```
Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
```

**Example 5:**

```
Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]
```

 

**Constraints:**

- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= intervals[i][0] <= intervals[i][1] <= 10^5`
- `intervals` is sorted by `intervals[i][0]` in **ascending** order.
- `newInterval.length == 2`
- `0 <= newInterval[0] <= newInterval[1] <= 10^5`



# [57. 插入区间](https://leetcode-cn.com/problems/insert-interval/)

难度中等

给你一个 **无重叠的** *，*按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 

**示例 1：**

```
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
```

**示例 2：**

```
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
```

**示例 3：**

```
输入：intervals = [], newInterval = [5,7]
输出：[[5,7]]
```

**示例 4：**

```
输入：intervals = [[1,5]], newInterval = [2,3]
输出：[[1,5]]
```

**示例 5：**

```
输入：intervals = [[1,5]], newInterval = [2,7]
输出：[[1,7]]
```

 

**提示：**

- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= intervals[i][0] <= intervals[i][1] <= 10^5`
- `intervals` 根据 `intervals[i][0]` 按 **升序** 排列
- `newInterval.length == 2`
- `0 <= newInterval[0] <= newInterval[1] <= 10^5`

