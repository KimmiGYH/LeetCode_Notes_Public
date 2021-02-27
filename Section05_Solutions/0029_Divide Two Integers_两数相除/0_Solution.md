# 29_Divide Two Integers_两数相除

## 解法一：快速幂思想(倍增作减法) $O(\log_{}{dividend})$

1. 根据 $dividend$ 和 $divisor$ 的符号判断最终答案的符号。

2. 如果 $dividend$ 或 $divisor$ 为负数，则先处理成绝对值，再用 $bool$ 作判断。

3. 如果每次暴力做减法去模拟除法，则时间复杂度为 $O(\frac{dividend}{divisor} )$，在 $divisor$ 较小，而 $dividend$ 较大的情况下会超时。

    ```cpp
    -2147483648
    -1
    商为 2147483648，但已超过 2^31 - 1，会爆 int，发生TLE错误
    ```

4. 所以需要用快速幂思想，或倍增作减法

![solve]()

5. 倒序遍历这个**倍增数组**，如果 $|dividend|$ 大于当前项，则让 $|dividend|$ 减去当前项，累计答案，以此类推。

**时间复杂度：**

- 倍增预处理最坏需要 $O(\log_{}{dividend})$ 的时间，遍历数组需要 $O(\log_{}{dividend})$ 的时间，故总时间复杂度为 $O(\log_{}{dividend})$。

**空间复杂度：**

- 需要额外 $O(\log_{}{dividend})$ 的空间存储倍增数组。
