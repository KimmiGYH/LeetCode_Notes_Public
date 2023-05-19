# 76. Minimum Window Substring_最小覆盖子串

## 解法一：(滑动窗口) $O(n)$ `Sliding Window`

- 首先用哈希表统计出 `T` 中所有字符出现的次数，哈希表可以用C++中的 `unordered_map`。
- 然后我们用两个指针 `i`,`j(i≥j)` 来扫描整个字符串，同时用一个哈希表统计 `i,j` 之间每种字符出现的次数，每次遍历需要的操作如下：

  - 加入 `s[i]`，同时更新哈希表；
  - 检查 `s[j]` 是否多余，如果是，则移除 `s[j]`；
  - 检查当前窗口是否已经满足 `T` 中所有字符，如果是，则更新答案；

**复杂度分析**
- 时间复杂度分析：两个指针都严格递增，最多移动 $n$ 次，所以总时间复杂度是 $O(n)$。



其他博主讲解：

basketWang: https://youtu.be/63i802XLgOM

山景城一姐：https://youtu.be/IzynHx-O4lE



# C++ 之 unordered_map——哈希表：

https://www.acwing.com/blog/content/9/

`unordered_map`是C++中的哈希表，可以在任意类型与类型之间做映射。

## **基本操作**

1. 引用头文件(C++11)：`#include <unordered_map>`
2. 定义：`unordered_map<int,int>`、`unordered_map<string, double>` ...
3. 插入：例如将`("ABC" -> 5.45)` 插入`unordered_map<string, double> hash`中，`hash["ABC"]=5.45`
4. 查询：`hash["ABC"]`会返回`5.45`
5. 判断key是否存在：`hash.count("ABC") != 0` 或 `hash.find("ABC") != hash.end()`
6. 遍历

```c++
for (auto &item : hash)
{
    cout << item.first << ' ' << item.second << endl;
}
```

或

```c++
for (unordered_map<string, double>::iterator it = hash.begin(); it != hash.end(); it ++ )
{
    cout << it->first << ' ' << it->second << endl;
}
```





## **进阶操作**

如果想让自定义的 class 作为 key  `(unordered_map<key,value>)` 来使用`unordered_map`，需要实现：
(1) 哈希函数，需要实现一个class重载`operator()`，将自定义class变量映射到一个 `size_t `类型的数。一般常用 `std::hash` 模板来实现。
(2) 判断两个自定义class类型的变量是否相等的函数，一般在自定义class里重载`operator==`。
示例代码：

```c++
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Myclass
{
public:
    int first;
    vector<int> second;

    // 重载等号，判断两个Myclass类型的变量是否相等
    bool operator== (const Myclass &other) const
    {
        return first == other.first && second == other.second;
    }

};

// 实现Myclass类的hash函数
namespace std
{
    template <>
    struct hash<Myclass>
    {
        size_t operator()(const Myclass &k) const
        {
            int h = k.first;
            for (auto x : k.second)
            {
                h ^= x;
            }
            return h;
        }
    };
}

int main()
{
    unordered_map<Myclass, double> S;
    Myclass a = { 2, {3, 4} };
    Myclass b = { 3, {1, 2, 3, 4} };
    S[a] = 2.5;
    S[b] = 3.123;
    cout << S[a] << ' ' << S[b] << endl;
    return 0;
}
```


输出:

```
2.5 3.123
```

