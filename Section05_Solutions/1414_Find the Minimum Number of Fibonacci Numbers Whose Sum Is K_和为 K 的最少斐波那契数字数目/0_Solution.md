# 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K_和为 K 的最少斐波那契数字数目 (Medium)



### 解法一：直接利用 Fibonacci 数组的性质，将 a, b 退回去

我们构造出所有小于等于 *k* 的斐波那契数，随后贪心地从大到小选取即可。

对于任意给定的 *k*，存在一种最优的选择方法，其中我们选择了不超过 *k* 的最大斐波那契数。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/1414_Find%20the%20Minimum%20Number%20of%20Fibonacci%20Numbers%20Whose%20Sum%20Is%20K_%E5%92%8C%E4%B8%BA%20K%20%E7%9A%84%E6%9C%80%E5%B0%91%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%AD%97%E6%95%B0%E7%9B%AE/solve.png)

1. 先列出 Fibonacci 数字：

   ```c++
   int a = 1, b = 1;
   while (b <= k) {
       swap(a, b);
       b += a;
   }
   ```

   示例：当 `k = 19` 时，`a = 13` , `b = 21`

2. 然后再利用 Fibonacci 数字的性质，将 `a`，`b`退回去

   ```c++
   b -= a;
   swap(a, b);
   ```

   

## 解法二：将 Fibonacci 数字放进 vector 递减循环判断 k



将 Fibonacci 数字列出来后放进 `vector`，然后递减循环判断 `vector` 最后的那个数 `fibo[i]` 与 `k` 的大小；

如果 `k >= fibo[i]`，则 `++res`，然后 `k -= fibo[i]`，继续判断，最终返回 `res` 个数。



### 解法三：二分优化

在解法二的基础上，使用二分搜索， **查找小于等于/小于 `k` 的最后一个元素**。

```c++
// 查找小于等于/小于 `k` 的最后一个元素
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

### 解法四：递归

递归求解 `findMinFibonacciNumbers(k - a)`，再加上 `1` 即 `k` 的情况。
