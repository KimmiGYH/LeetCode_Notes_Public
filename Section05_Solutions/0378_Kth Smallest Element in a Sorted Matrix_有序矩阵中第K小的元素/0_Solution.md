# 378_Kth Smallest Element in a Sorted Matrix_有序矩阵中第K小的元素



### 解法一：二分

**思路第一步**：我们可以二分答案，看一下答案是不是排名第 $k$ 位的。

- 假设二分出来的值是 $t$，如果 $t$ 排名是第 $k$ 位，那就意味着 $<=t$ 的个数是 $>=k$；
$=k$ 是显然的，$>$ 是因为后面可能有多个连续的 $t$；
所以 $<=t$ 的个数可能比 $k$ 多一些，也可能相等。
- 反过来，如果 $<=t$ 的个数是 $<k$ 的话，则说明 $t$ 是排在前 $k-1$ 位里的。
- 如果 $<=t$ 的个数是 $>=k$的，说明我们的答案要么是 $t$，要么比 $t$ 小，答案在左边；
- 反过来，如果 $<=t$ 的个数是 $<k$ 的话，说明 $t$ 太小了，答案在右边。

**思路第二步**：如何统计整个矩阵里小于等于 $t$ 的个数有多少个。

- 矩阵的性质，每行是递增的，每列也是递增的
- 第一行可以线性扫描 $<=t$ 是哪一段

**步骤：**

1. 二分下答案
2. 指针从后往前扫，所以时间复杂度是 $O(n)$ 的
3. `while (j >= 0 && mid < matrix[i][j]) j--;`
4. $cnt$ 的数量为 $j + 1$
5. 判断如果 $cnt >= k$，这说明答案是在左半边，$r = mid$



### 写法二：二分查找(力扣)

[力扣题解方法三](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/solution/you-xu-ju-zhen-zhong-di-kxiao-de-yuan-su-by-leetco/)

**思路及算法**

由题目给出的性质可知，这个矩阵内的元素是从左上到右下递增的（假设矩阵左上角为 `matrix[0][0]`）。以下图为例：

![pic1](https://assets.leetcode-cn.com/solution-static/378/378_fig1.png)

我们知道整个二维数组中 `matrix[0][0]` 为最小值，`matrix[n - 1][n - 1]` 为最大值，现在我们将其分别记作 `l` 和 `r`。

可以发现一个性质：任取一个数 $mid$ 满足 $l\leq mid \leq r$，那么矩阵中不大于 $mid$ 的数，肯定全部分布在矩阵的左上角。

例如下图，取 $mid=8$：

![pic2](https://assets.leetcode-cn.com/solution-static/378/378_fig2.png)

我们可以看到，矩阵中大于 $mid$ 的数就和不大于 $mid$ 的数分别形成了两个板块，沿着一条锯齿线将这个矩形分开。其中左上角板块的大小即为矩阵中不大于 $mid$ 的数的数量。

读者也可以自己取一些 $mid$ 值，通过画图以加深理解。

我们只要沿着这条锯齿线走一遍即可计算出这两个板块的大小，也自然就统计出了这个矩阵中不大于 $mid$ 的数的个数了。

走法演示如下，依然取 $mid=8$：

![pic3](https://assets.leetcode-cn.com/solution-static/378/378_fig3.png)

可以这样描述走法：

- 初始位置在 `matrix[n - 1][0]`（即左下角）；

- 设当前位置为 `matrix[i][j]`。若 $matrix[i][j] \leq mid$，则将当前所在列的不大于 $mid$ 的数的数量（即 $i + 1$）累加到答案中，并向右移动，否则向上移动；

- 不断移动直到走出格子为止。

我们发现这样的走法时间复杂度为 $O(n)$，即我们可以线性计算对于任意一个 $mid$，矩阵中有多少数不大于它。这满足了二分查找的性质。

不妨假设答案为 $x$，那么可以知道 $l\leq x\leq r$，这样就确定了二分查找的上下界。

每次对于「猜测」的答案 $mid$，计算矩阵中有多少数不大于 $mid$ ：
- 如果数量不少于 $k$，那么说明最终答案 $x$ 不大于 $mid$；
- 如果数量少于 $k$，那么说明最终答案 $x$ 大于 $mid$。

这样我们就可以计算出最终的结果 $x$ 了。

**代码**

```c++
class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int cnt = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {//左下角开始数
                cnt += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return cnt >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(n\log(r-l))$，二分查找进行次数为 $O(\log(r-l))$，每次操作时间复杂度为 $O(n)$。

- 空间复杂度：$O(1)$。

