# 1310_XOR Queries of a Subarray_子数组异或查询

## 解法一：前缀异或

### 写法一

本题主要利用异或运算中的相同数值进行运算结果为 $0$ （偶数次的异或结果为 $0$）的特性。

- 首先，定义前缀数组。`prexor[i]` 表示 `arr` 数组中，**前 `i+1` 个数的异或值**。即 $prexor[i] = arr[0] \oplus arr[1] \oplus \cdots \oplus arr[i-1] \oplus arr[i]$

- 其次，我们来观察一下这个数组的特性。取两个数 $L, R (L \le R)$，然后有
$\begin{cases}
 prexor[L-1] = arr[0] \oplus \cdots \oplus arr[L-1]\\
 prexor[R] = arr[0] \oplus \cdots \oplus arr[L-1] \oplus arr[L] \oplus \cdots arr[R]
\end{cases}$

    $prexor[L-1] \oplus prexor[R]\\$
    $=(arr[0] \oplus \cdots \oplus arr[L-1]) \oplus (arr[0] \oplus \cdots \oplus arr[R])\\$
    $=(arr[0] \oplus arr[0])\oplus \cdots \oplus(arr[L-1] \oplus arr[L-1])\oplus arr[L]\oplus \cdots \oplus arr[R]\\$
    $=arr[L]\oplus \cdots \oplus arr[R]\\$    

- 对 $L=0$ 的情况进行特殊判断，如果 $L==0$，则返回 $prexor[R]$
- 其他情况返回 $prexor[L-1] ^ prexor[R]$

### 写法二：前缀异或

**解题思路**：

本题采用类似前缀和的方法

- 首先预处理出一个前缀异或数组，时间复杂度：$O(arr.length)$
- 其次每次查询直接在这个数组中查询即可，每次查询只需要 $O(1)$ 时间，因此总的时间复杂度为 $O(queries.length)$
- 总的时间复杂度 $O(arr.length + queries.length)$

**为什么可以使用前缀数组？**

- 首先，定义前缀数组。`prexor[i]` 表示 `arr` 数组中，**前 `i` 个数的异或值**。即 $prexor[i] = arr[0] \oplus arr[1] \oplus \cdots \oplus arr[i-1]$
- 其次，我们来观察一下这个数组的特性。取两个数 $L, R (L \le R)$，然后有
$\begin{cases}
 prexor[L] = arr[0] \oplus \cdots \oplus arr[L-1]\\
 prexor[R] = arr[0] \oplus \cdots \oplus arr[L-1] \oplus arr[L] \oplus \cdots arr[R-1]
\end{cases}$

    $prexor[L] \oplus prexor[R]\\$
    $=(arr[0] \oplus \cdots \oplus arr[L-1]) \oplus (arr[0] \oplus \cdots \oplus arr[R-1])\\$
    $=(arr[0] \oplus arr[0])\oplus \cdots \oplus(arr[L-1] \oplus arr[L-1])\oplus arr[L]\oplus \cdots \oplus arr[R-1]\\$
    $=arr[L]\oplus \cdots \oplus arr[R-1]\\$

- 最后，基于以上的性质，我们只需要代入 $L$, $R+1$，即可得到。

**一些有趣的思考**：

本题中，在前缀数组中增加了一个哨兵，这样不需要对 $L=0$ 的情况进行特殊判断。

## 解法二：树状数组


