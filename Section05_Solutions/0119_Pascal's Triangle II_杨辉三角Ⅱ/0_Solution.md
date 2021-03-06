# 119_Pascal's Triangle II_杨辉三角Ⅱ (Easy)

## 解法一：递推，滚动数组 $O(n^2)$

- 一行一行计算，由于每行的值仅与上一行的值有关，所以可以用**滚动数组**优化。

- 计算每一行的值时，先将 `1` 放在首尾两个位置，然后计算中间的数：$f[i][j] = f[i-1][j-1] + f[i-1][j]$；

**时间复杂度分析：**

- 假设行数是 $n$，则总共有 $n∗(n+1)/2$ 个状态，计算每个状态的时间复杂度是 $O(1)$，所以总时间复杂度是 $O(n^2)$。


## 解法二：数学 - 组合 $O(n)$

1. 对于杨辉三角形来说，每一行的元素都是 $(x + y)^k$ 的展开式的对应的系数，从第 $0$ 行开始计算；

    ![杨辉三角形](https://pic.leetcode-cn.com/fcde665c91e6cdda4a8009c4bff7b044bf93586c2c1fa60b4232c973686ab9a1-gif.latex.gif)

2. 对于第 $k$ 行，一共有 $k + 1$ 个元素，分别对应的是 $C_k^0$，$C_k^1$，$C_k^2$，…… ，$C_k^k$；

3. 给定 $k$ 时，可以直接通过公式计算出第 $k$ 行的所有元素。

4. 既然如此，那么第 $i$ 行第 $j$ 个数的公式就是 $\frac{i!}{j!*(i-j)!}$，这样就以在线性时间内得出答案了。

5. 前面一项与后面一项的比值为：

   $C_n^{m-1} \div C_n^m$ 
   = $\frac{n!}{!(m-1) \cdot (n-m+1)!} \div \frac{n!}{!(m) \cdot (n-m)!}
   =\frac{m}{n-m+1}$

   从后往前遍历， `val` 乘的时候不能直接乘这个比值，而应该分两步：

    ```cpp
    for (int m = n; m >= 1; --m) {
        val *= m;
        val /= n - m + 1;
        res.push_back(val);
    }
    ```