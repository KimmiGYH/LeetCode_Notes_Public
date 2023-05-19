# 0204_Count Primes_计数质数 (Easy)

笔记：https://www.acwing.com/activity/content/code/content/1643811/

### 解法一：Eratosthenes 筛法（埃拉托斯特尼筛法，简称埃氏筛法），时间复杂度是 $O(nloglogn)$

```c++
int n;
vector<char> is_prime(n + 1, true);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i * i <= n; i++) {
  if (is_prime[i]) {
    for (int j = i * i; j <= n; j += i) is_prime[j] = false;
  }
}
```


### 解法二：Euler 筛法（线性筛），时间复杂度是 $O(n)$

```c++
void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true; //素数的i倍筛掉
            if (i % primes[j] == 0) break; //当前素数为i的最小质因子，分析下个i
        }
    }
}
```