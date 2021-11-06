# 7_Reverse Integer_整数反转

## 解法一：数学（秦九韶算法）

- 把整数的每位抠出来可以：每次模 $10$ 把个位输出来，然后再 `/ 10` 把个位删掉

    ```cpp
    // 模板:
    r = r * 10 + x % 10;
    x = x / 10;
    ```

    ```cpp
    int x = 1234;

    x % 10; // 把个位拿出来
    x / 10; // 把个位删掉
    ```

- 再把 $4321$ 变成整数

    ```cpp
    // 秦九韶算法：
    r = 0
    r = r * 10 + 4 = 4
    r = r * 10 + 3 = 43
    r = r * 10 + 2 = 432
    r = r * 10 + 1 = 4321
    ```

    **代码**：

    ```cpp
    int x = 1234;
    int r = 0;
    while (x)
    {
        r = r * 10 + x % 10;
        x /= 10;
    }
    ```

- 代码也适用于负数

## 写法二：用 `int` 存，不用 `long long` 存

```cpp
class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            if (r > INT_MAX / 10) return 0;
            if (r < INT_MIN / 10) return 0;
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;        
    }
};
```

条件判断还可以写成：

```cpp
if (r > 0 && r > (INT_MAX - x % 10) / 10) return 0;
if (r < 0 && r < (INT_MIN - x % 10) / 10) return 0;
```

注意不能写成以下情况：

```cpp
if (r > (INT_MAX - x % 10) / 10) return 0;
if (r < (INT_MIN - x % 10) / 10) return 0;
```

因为，`INT_MAX - (-k)` 就已经溢出了，同理 `INTMIN - k` 也已经溢出了。（ `k` 为正数）
