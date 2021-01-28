# **算法知识**：`nth_element`

`nth_element` 是部分排序算法，它重排 $[first, last)$ 中元素，使得：

- $nth$ 所指向的元素被更改为假如 $[first, last)$ 已排序则该位置会出现的元素。
- 这个新的 $nth$ 元素前的所有元素小于或等于新的 $nth$ 元素后的所有元素。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
 
int main()
{
    std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
 
    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
    std::cout << "The median is " << v[v.size()/2] << '\n';
 
    std::nth_element(v.begin(), v.begin()+1, v.end(), std::greater<int>());
    std::cout << "The second largest element is " << v[1] << '\n';
}

/*输出：
The median is 5
The second largest element is 7
*/
```

Related problem: [AcWing 104. 货仓选址](https://www.acwing.com/problem/content/description/106/)
