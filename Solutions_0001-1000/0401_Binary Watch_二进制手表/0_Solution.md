# 401. Binary Watch_二进制手表 (Medium)



## 解法一：



### 重点 1)：

```c++
// 直接遍历  0:00 -> 12:00   每个时间有多少 1
for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 60; j++) {
        
    }
}
```



### 重点 2)：计算二进制中 `1` 的个数（四种写法）

写法一：

```c++
// 计算二进制中 1 的个数
int count1(int n) {
    int res = 0;
    while (n != 0) {
        n = n & (n - 1); // 将 u 最右边的 1 清除
        res++;
    }
    return res;
}
```

写法二：[二进制中的1的个数](https://www.acwing.com/video/1097/)

```c++
// 计算二进制中 1 的个数
int count1(int n) {
    int res = 0;
    while (n) {
        n -= n & -n; // lowbit 写法
        res++;
    }
    return res;
}
```

写法三：

```c++
// 计算二进制中 1 的个数
int count1(int n) {
    int res = 0;
    while (n) {
		res += n & 1, n >>= 1;
    }
    return res;
}
```

写法四：直接用 `__builtin_popcount`

```c++
// 内置函数 __builtin_popcount()
if (__builtin_popcount(i) + __builtin_popcount(j) == num) {
    
}
```



## 解法二：



问有多少个灯是亮的，换句话是问我们一天的所有时间表示里，有多少个二进制表示里恰好有 `n` 个 `1`。

解法：

枚举二进制表示的所有情况，判断一下如果当前二进制表示里恰好有 `n ` 个 `1`，并且这个二进制表示是一个合法时间的话，那么就把这个时间输出即可。



### 重点 1)：

由于总共有 10 个灯，10 个位置：

```c++
for (int i = 0; i < 1 << 10; i++) {
	for (int j = 0; j < 10; j++) {
        if (i >> j & 1) // 或者写成 if (i & (1 << j)) 
            s++; // 计数，计算有几个 1 或者说有几个灯是亮着的
    }
}
```



### 重点 2)：

当计数与题目给的灯亮着的数量一致时，返回对应的**小时**和**分钟**：

```c++
// 前者返回最高的四位，后者返回最低的六位
int hour = i >> 6, minute = i & 63;
```

