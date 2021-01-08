# 399. Evaluate Division_除法求值(Medium)



## 解法一：带权图 DFS

![solve1_Graph_DFS]()

题目给到：

```cpp
输入：
    equations = [["a","b"],["b","c"]], 
    values = [2.0,3.0], 
    queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
输出：[6.00000, 0.50000, -1.00000, 1.00000, -1.00000]
        
解释：
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
```



设置这样的数据结构，

```cpp
unordered_map<string, unordered_map<string, double>> g;
```

用来存放下列数据

```cpp
g{
    {"a", {"b", 2.0}}, {"b", {"c", 3.0}},
    {"b", {"a", 1/2}}, {"c", {"b", 1/3}}
};
```



生成的**邻接矩阵**（Adjacency Matrix是表示顶点之间相邻关系的矩阵）如下：

![solve1_Adjacency_Matrix]()



思路就是已知 `g[X][Y]`，要求出 `g[X][Z]`，只需要先递归求出 `g[Y][Z]`，

即 `X/Z = Y/Z * X/Y`。



## 解法二：带权并查集

[力扣官方题解链接](https://leetcode-cn.com/problems/evaluate-division/solution/chu-fa-qiu-zhi-by-leetcode-solution-8nxb/)



我们还可以考虑以并查集的方式存储节点之间的关系。

设节点 `x` 的值（即对应变量的取值）为 `v[x]`。对于任意两点 `x, y`，假设它们在并查集中具有共同的父亲 `f`，且 `v[x]/v[f] = a`, `v[y]/v[f]=b`，则 `v[x]/v[y] = a/b`。

```cpp
条件：a / b = 2.0, b / c = 3.0
问题：a / c = ?
    
思路：a / b = 2.0, c / b = 1 / 3.0
```



在观察到这一点后，就不难利用并查集的思想解决此题。对于每个节点 `x` 而言，除了维护其父亲 `f[x]` 之外，还要维护其权值 `w`，其中「权值」定义为节点 `x` 的取值与父亲 `f[x]` 的取值之间的比值。换言之，我们有
$$
w[x] = \frac{v[x]}{v[f[x]]}
$$
下面，我们对并查集的两种操作的实现细节做出讨论。

**当查询节点 `x` 父亲时**，如果 `f[x] ≠ x`，我们需要先找到 `f[x]` 的父亲 `father`，并将 `f[x]` 更新为 `father`。此时，我们有
$$
w[x]\leftarrow \frac{v[x]}{v[father]} 
\\=\frac{v[x]}{v[f[x]]}\cdot\frac{v[f[x]]}{v[father]}
\\=w[x] \cdot w[f[x]]
$$
也就是说，我们要将 `w[x]`更新为 `w[x]·f[x]`。



**当合并两个节点 `x,y`时**，我们首先找到两者的父亲 `fx`, `fy`，并将 `f[f[x]]` 更新为 `fy`。此时，我们有

$$
w[f[x]]\leftarrow \frac{v[fx]}{v[fy]} 
\\=\frac{v[x]/w[x]} {v[y]/w[y]}
\\=\frac{v[x]}{v[y]}\cdot\frac{w[y]}{w[x]}
$$

也就是说，当在已有的图中添加一条方程式
$$
\frac{v[x]}{v[y]} = k
$$
时，需要将 `w[fx]` 更新为
$$
k\cdot\frac{w[y]}{w[x]}
$$

## 解法三：

