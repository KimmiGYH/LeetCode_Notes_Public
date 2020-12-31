# 639. Decode Ways II_解码方法 2



## 解法一：朴素方法

![asterisk](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0639_Decode%20Ways%20II_%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95%202/asterisk.png)



![solve1](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0639_Decode%20Ways%20II_%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95%202/solve1.png)



## 解法二：

![solve2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0639_Decode%20Ways%20II_%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95%202/solve2.png)



## 解法三（看不太懂）：

定义了一系列的变量 `e0`, `e1`, `e2`, `f0`, `f1`, `f2`。其中：

`e0` 表示当前可以获得的解码的次数，当前数字可以为任意数 (也就是上面解法中的 `dp[i]`)

`e1` 表示当前可以获得的解码的次数，当前数字为 `1`;

`e2` 表示当前可以获得的解码的次数，当前数字为 `2`;

`f0`, `f1`, `f2` 分别为处理完当前字符 `c` 的 `e0`, `e1`, `e2` 的值。



那么下面我们来进行分类讨论：

当 `c` 为星号 `* ` 的时候，`f0` 的值就是 `9*e0 + 9*e1 + 6*e2`，这个应该不难理解了，可以参考上面解法中的讲解，这里的 `e0` 就相当于`dp[i-1]`，`e1` 和 `e2` 相当于两种不同情况的 `dp[i-2]`，此时 `f1` 和 `f2` 都赋值为 `e0`，因为要和后面的数字组成两位数的话，不会增加新的解码方法，所以解码总数跟之前的一样，为 `e0`, 即 `dp[i-1]`。

当 `c` 不为星号的时候，如果 `c` 不为 `0`，则 `f0` 首先应该加上 `e0`。然后不管 `c` 为何值，`e1` 都需要加上，总能和前面的 `1` 组成两位数；如果 `c` 小于等于 `6`，可以和前面的 `2` 组成两位数，可以加上 `e2`。然后我们更新 `f1` 和 `f2`，如果 `c` 为 `1`，则 `f1` 为 `e0`；如果 `c` 为 `2`，则 `f2` 为 `e0`。

最后别忘了将 `f0`，`f1`，`f2` 赋值给 `e0`，`e1`，`e2`，其中 `f0` 需要对超大数取余。