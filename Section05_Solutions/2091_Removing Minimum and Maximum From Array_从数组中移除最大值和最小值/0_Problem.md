# [2091. Removing Minimum and Maximum From Array](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/) (Medium)

You are given a **0-indexed** array of **distinct** integers `nums`.

There is an element in `nums` that has the **lowest** value and an element that has the **highest** value. We call them the **minimum** and **maximum** respectively. Your goal is to remove **both** these elements from the array.

A **deletion** is defined as either removing an element from the **front** of the array or removing an element from the **back** of the array.

Return *the **minimum** number of deletions it would take to remove **both** the minimum and maximum element from the array.*

 

**Example 1:**

```
Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
```

**Example 2:**

```
Input: nums = [0,-4,19,1,8,-2,-3,5]
Output: 3
Explanation: 
The minimum element in the array is nums[1], which is -4.
The maximum element in the array is nums[2], which is 19.
We can remove both the minimum and maximum by removing 3 elements from the front.
This results in only 3 deletions, which is the minimum number possible.
```

**Example 3:**

```
Input: nums = [101]
Output: 1
Explanation:  
There is only one element in the array, which makes it both the minimum and maximum element.
We can remove it with 1 deletion.
```

 

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`
- The integers in `nums` are **distinct**.



# [5940. 从数组中移除最大值和最小值](https://leetcode-cn.com/problems/removing-minimum-and-maximum-from-array/)

难度中等

给你一个下标从 **0** 开始的数组 `nums` ，数组由若干 **互不相同** 的整数组成。

`nums` 中有一个值最小的元素和一个值最大的元素。分别称为 **最小值** 和 **最大值** 。你的目标是从数组中移除这两个元素。

一次 **删除** 操作定义为从数组的 **前面** 移除一个元素或从数组的 **后面** 移除一个元素。

返回将数组中最小值和最大值 **都** 移除需要的最小删除次数。

 

**示例 1：**

```
输入：nums = [2,10,7,5,4,1,8,6]
输出：5
解释：
数组中的最小元素是 nums[5] ，值为 1 。
数组中的最大元素是 nums[1] ，值为 10 。
将最大值和最小值都移除需要从数组前面移除 2 个元素，从数组后面移除 3 个元素。
结果是 2 + 3 = 5 ，这是所有可能情况中的最小删除次数。
```

**示例 2：**

```
输入：nums = [0,-4,19,1,8,-2,-3,5]
输出：3
解释：
数组中的最小元素是 nums[1] ，值为 -4 。
数组中的最大元素是 nums[2] ，值为 19 。
将最大值和最小值都移除需要从数组前面移除 3 个元素。
结果是 3 ，这是所有可能情况中的最小删除次数。 
```

**示例 3：**

```
输入：nums = [101]
输出：1
解释：
数组中只有这一个元素，那么它既是数组中的最小值又是数组中的最大值。
移除它只需要 1 次删除操作。
```

 

**提示：**

- `1 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`
- `nums` 中的整数 **互不相同**