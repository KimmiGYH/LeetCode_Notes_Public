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





# set和map不同底层实现的区别

常见操作：

- `insert`
- `find`
- `erase`
- `change(map)`



|      | 普通数组实现 | 顺序数组实现 | 二分搜索树（平衡） | 哈希表 |
| ---- | ------------ | ------------ | ------------------ | ------ |
| 插入 | `O(1)`       | `O(n)`       | `O(logn)`          | `O(1)` |
| 查找 | `O(n)`       | `O(logn)`    | `O(logn)`          | `O(1)` |
| 删除 | `O(n)`       | `O(n)`       | `O(logn)`          | `O(1)` |

但是哈希表会失去数据的顺序性：

- 数据集中的最大值和最小值
- 某个元素的前驱和后继
- 某个元素的`floor`和`ceil`
- 某个元素的排位`rank`
- 选择某个排位的元素`select`

 

C++语言中，`map`和`set`的底层实现为平衡二叉树。

`unordered_map`和`unordered_set`的底层实现为哈希表。









