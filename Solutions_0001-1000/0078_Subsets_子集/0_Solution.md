# 78. Subsets_子集 (Medium)

## 解法一：DFS

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0078_Subsets_%E5%AD%90%E9%9B%86/%E6%8E%92%E5%88%97%E7%BB%84%E5%90%88%E6%A8%A1%E6%9D%BF_LC78.png)

## 解法二：位运算

[花花酱 LeetCode 78. Subsets](https://youtu.be/CUzm-buvH_8?t=900)




```c++
[0,1,2]
//可以让每一位表示这个数选不选，由此可以用二进制数来表示选择的方案
//2 1 0
  0 0 0
  0 0 1
  0 1 0
  0 1 1
  1 0 0
  1 0 1
  1 1 0
  1 1 1
```


```c++
// use 9 bit binary string to represent a combination
000000000	->	[]
000000001	->	[1]
...
000100011	->	[1,2,6]
...
111111110	->	[2,3,4,5,6,7,8,9]
111111111	->	[1,2,3,4,5,6,7,8,9]
```



### 两种写法：

写法一：花花酱

```c++
        for (int i = 0; i < 1 << n; ++i) {
            vector<int> path;
            for (int j = 0; j < n; ++j)
                // & 一下，以确定第 j 位是不是 1
                if (i & (1 << j))
                    path.push_back(nums[j]);
```



写法二：y总

```c++
        for (int i = 0; i < 1 << n; i++) {
            vector<int> path;
            for (int j = 0; j < n; j++)
                // 先把第 j 位移到最后一位，再 & 1，看 i 的第 j 位 是 1 还是 0?
                if (i >> j & 1)
                    path.push_back(nums[j]);
```



#### (集合的二进制表示) $O(2^n n)$

假设集合大小是  `n`，我们枚举 $0…2^n−1$，一共 $2^n$ 个数。

每个数表示一个子集，假设这个数的二进制表示的第 `i` 位是 `1`，则表示该子集包含第 `i` 个数，否则表示不包含。

另外，如果 `n ≥ 30`，则 $2^n ≥ 10^9$，肯定会超时，所以我们可以断定 `n ≤ 30`，可以用 int 型变量来枚举。

##### 时间复杂度分析

一共枚举 $2^n$ 个数，每个数枚举 `n` 位，所以总时间复杂度是 $O(2^n n)$。



------



### 位运算输出二进制数

位运算：

- 求 `n` 的第 `k` 位数字： `n >> k & 1`



`n` 的二进制表示中第 `k` 位是几？

eg. n = 15 = (1111)~2~

(1) 先把第 `k` 位移到最后一位， `n >> k`

(2) 看个位是几？比如想看 x 的个位是几，则 `x & 1`即可

(1) + (2)： `n >> k & 1` 求 `n` 的第 `k` 位数字是几，是 `1` 还是 `0` ？



```c++
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n = 10;
    for (int k = 3; k >= 0; k--)
        cout << (n >> k & 1);
    
    return 0;
}

/** Output: 
1010
*/
```

