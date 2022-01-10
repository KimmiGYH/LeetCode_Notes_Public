# decltype 的用法

[链接](https://leetcode-cn.com/circle/discuss/hOc5b1/)

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&CMP)> q(CMP);
```

### 解释：
一、

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&CMP)> q(CMP);
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(CMP)*> q(CMP);
priority_queue<pair<int, int>, vector<pair<int, int>>,  bool (*)CMP(pair<int, int>&, pair<int, int>&)> q(CMP);
priority_queue<pair<int, int>, vector<pair<int, int>>, function< bool(pair<int, int>&, pair<int, int>&)> > q(CMP);
```
第三个模板参数需要填入的是一个函数指针(function **pointer**)，而不是一个函数类型(function type)，尽管在某些地方函数名会退化为指针但是实际上还是不一样（可以用 `typeid()` 验证），所以 `decltype` 不能将 `&` 符号去掉。

二、

对于 $lambda$ 表达式生成的比较函数 `auto CMP = [&](int u, int v)-> bool{return notes[u] > notes[v];};`，这里所谓的 $auto$ 其实就是一个 `std::function<...>` 所以不需要再取指针。

```cpp
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(CMP)> q(CMP);
```

而对于构造函数参数，这里是不可以省略的，`std::less<>` 可以省略是因为 `functor class` 有自己默认的构造函数。
