# 990. Satisfiability of Equality Equations_等式方程的可满足性 (Medium)



## 解法一：(并查集) $O(n)$

1. 第一次遍历相等判定的公式，然后将对应的变量放入到同一集合中。

2. 第二次遍历所有不等的公式，如果对应的变量出现在了同一集合中，则说明不合法，返回 `false`。
3. 如果没有矛盾，返回 `true`。

**时间复杂度**

- 假设并查集的操作时间复杂度为常数，则算法只需要遍历所有的公式，故时间复杂度为 $O(n)$。

**空间复杂度**

- 由于只有 `26` 个字母，所以只需要常数的空间。



------



### 并查集模板：



#### (1) 朴素并查集：

```cpp
    int p[N]; //存储每个点的祖宗节点

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);
```



#### (2) 维护 `size` 的并查集：

```cpp
    int p[N], size[N];
    //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    // 合并a和b所在的两个集合：
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);
```