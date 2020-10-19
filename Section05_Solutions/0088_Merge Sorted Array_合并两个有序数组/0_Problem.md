
# 88. Merge Sorted Array (Easy)

Given two sorted integer arrays *nums1* and *nums2*, merge *nums2* into *nums1* as one sorted array.

**Note:**

*   The number of elements initialized in *nums1* and *nums2* are *m* and *n* respectively.
*   You may assume that *nums1* has enough space (size that is **equal** to *m* + *n*) to hold additional elements from *nums2*.

**Example:**

**Input:**
nums1 = \[1,2,3,0,0,0\], m = 3
nums2 = \[2,5,6\],       n = 3

**Output:** \[1,2,2,3,5,6\]

**Constraints:**

*   `-10^9 <= nums1[i], nums2[i] <= 10^9`
*   `nums1.length == m + n`
*   `nums2.length == n`



# [88\. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

难度简单665

给你两个有序整数数组 *nums1* 和 *nums2*，请你将 *nums2* 合并到 *nums1* 中*，*使 *nums1* 成为一个有序数组。

**说明：**

*   初始化 *nums1* 和 *nums2* 的元素数量分别为 *m* 和 *n* 。
*   你可以假设 *nums1* 有足够的空间（空间大小大于或等于 *m + n*）来保存 *nums2* 中的元素。

**示例：**

**输入：**
nums1 = \[1,2,3,0,0,0\], m = 3
nums2 = \[2,5,6\],       n = 3

**输出：**\[1,2,2,3,5,6\]

**提示：**

*   `-10^9 <= nums1[i], nums2[i] <= 10^9`
*   `nums1.length == m + n`
*   `nums2.length == n`


# 题目大意
合并两个已经有序的数组，结果放在第⼀个数组中，第⼀个数组假设空间⾜够⼤。要求算法时间复杂度⾜够低。

