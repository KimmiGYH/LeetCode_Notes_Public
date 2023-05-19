# [119. Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/) (Easy)

Given an integer `rowIndex`, return the `rowIndexth` row of the Pascal's triangle.

Notice that the row index starts from **0**.

![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
In Pascal's triangle, each number is the sum of the two numbers directly above it.

**Follow up:**

Could you optimize your algorithm to use only *O*(*k*) extra space?

 

**Example 1:**

```
Input: rowIndex = 3
Output: [1,3,3,1]
```

**Example 2:**

```
Input: rowIndex = 0
Output: [1]
```

**Example 3:**

```
Input: rowIndex = 1
Output: [1,1]
```

 

**Constraints:**

- `0 <= rowIndex <= 33`



# [119. 杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)

难度简单

给定一个非负索引 *k*，其中 *k* ≤ 33，返回杨辉三角的第 *k* 行。

![img](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

在杨辉三角中，每个数是它左上方和右上方的数的和。

**示例:**

```
输入: 3
输出: [1,3,3,1]
```

**进阶：**

你可以优化你的算法到 *O*(*k*) 空间复杂度吗？