# 398. Random Pick Index_随机数索引 (Medium)



## 解法一：蓄水池抽样

```c++
下标	0	1	2	3	4

数值	1	2	3	3	3
```



利用一个 `unordered_map<int, vector<int>> hash` 存储每个数值对应的下标，那么随机返回一个索引，

其实就是生成一个`0 ~ (hash[target].size() - 1)`的一个随机数，这样如果存在多次 `pick`，那么每次都是 $O(1)$ 的效率。

生成随机数的代码：

```c++
// 返回随机的索引
return hash[target][rand() % hash[target].size()];
```

