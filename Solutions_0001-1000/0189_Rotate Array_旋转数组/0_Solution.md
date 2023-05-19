# 189. Rotate Array_旋转数组 (Medium)



## 解法一：翻转字符



翻转字符的方法，思路是：

- 先把整个数组翻转
- 由于现在整个数组是逆序的，所以把前 `k` 个数翻转
- 再把后面的 `n-k` 个数翻转一下

```c++
1 2 3 4 5 6 7
7 6 5 4 3 2 1
5 6 7
      1 2 3 4
5 6 7 1 2 3 4
```



## 解法二：STL

旋转数组的操作可以看做从数组的开头取 `n - k` 个数放入数组的末尾。

我们可以用 STL 的 `push_back` 和 `erase` 可以很容易地实现这些操作。

```cpp
#include <vector>
#include <iostream>
 
 
int main( )
{
    std::vector<int> c{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    // 0 1 2 3 4 5 6 7 8 9

 
    c.erase(c.begin());
 
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    // 1 2 3 4 5 6 7 8 9
 

    c.erase(c.begin()+2, c.begin()+5);
 
    for (auto &i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    // 1 2 6 7 8 9
}
```
