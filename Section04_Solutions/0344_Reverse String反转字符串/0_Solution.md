# 0344_Reverse String反转字符串

## 方法一：双指针法

这⼀题的解题思路是⽤ 2 个指针，指针对撞的思路，来不断交换⾸尾元素，用到`swap`函数。

## 方法二：直接用`reverse()`函数

```cpp
reverse(s.begin(), s.end());
```
