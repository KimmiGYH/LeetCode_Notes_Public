## C++数组或vector求最大值最小值

可以用 `max_element()` 及 `min_element()` 函数，二者返回的都是迭代器或指针。

头文件：`#include<algorithm>`


### 1.求数组的最大值或最小值

1）vector容器

例 vector<int> vec

最大值：`int maxValue = *max_element(v.begin(),v.end());` 

最小值：`int minValue = *min_element(v.begin(),v.end());`

2）普通数组

例 a[]={1,2,3,4,5,6};

最大值：`int maxValue = *max_element(a,a+6);`

最小值：`int minValue = *min_element(a,a+6);`


### 2.求数组最大值最小值对应的下标

1）vector容器

例 `vector<int> vec`

最大值下标：`int maxPosition = max_element(v.begin(),v.end()) - v.begin();`

最小值下标：`int minPosition = min_element(v.begin(),v.end()) - v.begin();`

2）普通数组

例 `a[]={1,2,3,4,5,6};`

最大值下标：`int maxPosition = max_element(a,a+6) - a;`

最小值下标：`int minPosition = min_element(a,a+6) - a;`


注意：返回的是第一个最大（小）元素的位置。
