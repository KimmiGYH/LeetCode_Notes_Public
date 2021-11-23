# 0528_Random Pick with Weight_按权重随机选择

举例：

- `[0, 1, 2]` 为$[0, w.size()-1]$权重的下标
- `[1, 2, 3]` 为第 $i$ 个下标权重；前缀和：`[1, 3, 6]`
- `0 1 1 2 2 2` 为范围内下标的分布
- `[0][1,2][3,4,5]` 为分布的下标
- `int x = rand() % 6;` 对应为 $0,1,2,3,4,5$
- `int x = rand() % 6 + 1;` 为 $1,2,3,4,5,6$，找出第一个 $\ge x$ 的数，比如 $\ge x = 4$，对应前缀和里的 $6$ 的下标为 $2$。


**四种写法：前缀和+二分查找**

写法一：`lower_bound()`

写法二：lower 对应的手写二分

写法三：`upper_bound`

写法四：upper 对应的手写二分

对于 `lower_bound()` （求第一个 ≥ x 的数）和 `upper_bound()`（求第一个 > x 的数）都可以这套二分模板

```cpp
// 对应lower_bound()
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (A[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}
```

```cpp
// 对应upper_bound()
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (A[mid] > target) r = mid; //只要这里改成 >target即可
        else l = mid + 1;
    }
    return l;
}
```



