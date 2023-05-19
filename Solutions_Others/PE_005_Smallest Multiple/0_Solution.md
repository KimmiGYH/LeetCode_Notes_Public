
# Euclidean Algorithm

## 005 Smallest multiple: 232792560

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

:heart: **Solution #1 Euclidean Algorithm** 

```cpp
// 欧几里得算法 —— 模板
int gcd(int a, int b)
{
    // b 是否为非零数？是的话返回 gcd(b, a % b);
    // 否则如果 b 是零，零能整除任何数，则返回 a。
    return b ? gcd(b, a % b) : a;
}
```

```python
# 第5题 找到了一个比较简便的方法
#主要思路：先求 1*2的最小公倍数(lsm) 设为x, 再求x*3的lsm 比如y，再求y*4的lsm z，再求 z*5的lsm，以此类推
# Solution to Project Euler problem 5
# Least common multiple of (1 - 20)

# ===== Lastdrop's method =====

from functools import reduce

def gcd(a, b):
    
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
    
    # return gcd(b, a%b) if b else a

def lcm(a, b):
    return a * b // gcd(a, b)

def solve(n = 20):
    return reduce(lcm, range(1, n+1))

print(solve())


# ===== Marcus's method =====
# https://projecteuler.net/thread=5;page=5#105775

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a*b / gcd(a, b)

def solve(n = 20):    
    ans = 1
    for i in range(2, n + 1):
        ans = lcm(i, ans)
    return ans

print(solve())


# ===== Combine lastdrop and Marcus =====
# Let me translate lastdrop's program into easily comprehensible code, lmao

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

def solve(n = 20):
    ans = 1
    for i in range(2, n + 1):
        ans = lcm(i, ans)
    return ans

print(solve())
```