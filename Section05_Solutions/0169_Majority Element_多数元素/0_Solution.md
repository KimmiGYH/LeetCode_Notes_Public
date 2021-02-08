# 169_Majority Element_多数元素

## 解法一：摩尔投票算法

- $r$ 表示当前这个数
- $c$ 表示当前这个数的库存
- 如果没有库存，就将遍历的数 $x$ 赋给 $r$，$c$ 更新为 $1$
- 如果 $r == x$，则将 $c++$，否则 $c--$

**摩尔投票算法**，基于一个事实：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个。

**思路**：定义一个计数的变量 $c$，当 $c$ 为 $0$ 时，将 $res$ 赋为当前的数 $x$；当 $c$ 不为 $0$ 时，判断当前的 $x$ 与 $res$ 是否相等，相等则 $c$ 的数量加一，否则减一。
最后再次遍历数组，统计与当前 $res$ 相等的数字的个数，然后判断其总数是否过半。

[LeetCode 面试题 17.10. 主要元素](https://leetcode-cn.com/problems/find-majority-element-lcci/)

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r, c = 0;
        for (auto& x : nums)
            if (!c) r = x, c = 1;
            else if (r == x) c++;
            else c--;
        c = 0;
        for (auto& x : nums) if (x == r) c++;
        if (c*2 > nums.size()) return r;
        else return -1;
    }
};
```
