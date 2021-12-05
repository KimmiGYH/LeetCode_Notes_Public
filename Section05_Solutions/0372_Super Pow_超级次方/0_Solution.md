# 372_Super Pow_超级次方

**快速幂模板**

```cpp
#include <iostream>

using namespace std;

typedef long long LL;

int main()
{
    int a, b, p;
    cin >> a >> b >> p;

    // int res = 1; // 数据  123456789 0 1 会出错
    int res = 1 % p; //防止 b=0, p=1 的情况
    while (b) {
        //如果b的个位为1，b是奇数，那么拿一个a出来
        // 1ll是long long类型的整数1
        if (b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p; //底数自乘
        b >>= 1; //再把个位去掉，即指数除2
    }
    cout << res << endl;

    return 0;
}
```

```cpp
// 举例：(p随便取个模)
// 如果 b 是奇数，就取个 a 出来乘到 res 上，之后底数 a 自乘，指数 b 除 2（右移1位）
res  a  b  p    
1    3  7  1008
3    9  3
27   81 1
27 * 81 % 1008 = 171
```

## 解法一：快速幂+秦九韶算法直接求指数(错误，会爆longlong)

！错误：直接求指数：
```cpp
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (a == 1) return 1;
        typedef long long LL;
        int p = 1337;
        LL r = 0, res = 1;
        for (auto& x : b) {
            r = r * 10 + 1ll * x;
        }
        while (r) {
            if (r & 1) res = (LL)res * a % p;
            a = (LL)a * a % p;
            r >>= 1;
        }
        return res;
    }
};
```
- 由于数据范围可以超级大，比如 $1774317014492850093 * 10$，会爆 $long long$
```cpp
runtime error: signed integer overflow: 1774317014492850093 * 10 cannot be represented in type 'long long' (solution.cpp)
```
- 所以必须先模，再求指数

## 解法二：快速幂+递归

- 用递归，举个例子，比如 $b$数组为 $[2, 3, 4]$，指数可以分成 $234 = 230 + 4 = 23 * 10 +4$

- $a^{234} = (a^{23})^{10} * a^{4}$
- 取出 $b$ 数组的最后一个元素，并把最后元素 `pop_back()` 掉
- 递归调用 $superPow$ 函数得到 $a^{23}$
- 再用快速幂函数求 $(superPow(a,b))^{10} * a^{4}$，得到 $(a^{23})^{10} * a^{4} = a^{234}$

**时间复杂度**：
- 假设 $b$ 数组所代表的数字为 $K$，使用快速幂的复杂度为 $O(logK)$，或者说是 $O(n∗log10)$，其中 $n$ 为数组 $b$ 的长度，数字 $10$ 所代表的含义是计算一个次方为 $10$ 以内的值；而不使用快速幂的复杂度为 $O(n∗10)$

**空间复杂度**：
- 忽略递归带来的额外空间开销，复杂度为 $O(1)$


## 解法三：秦九韶算法+非递归+快速幂

- 举例 $b$数组为 $[2, 3, 4]$，那么
$a^{234} = (a^{230})*(a^{4}) = (a^{23})^{10}*(a^{4})$

- 同样的里面的 $a^{23} = a^{20} * a^{3} = (a^{2})^{10} * a^{3}$

- 所以可以这么求指数：
```cpp
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int& x : b) {
            res = pow(res, 10) * pow(a, x) % MOD;
        }
        return res;
    }
```