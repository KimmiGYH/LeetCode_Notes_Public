# 1296_Divide Array in Sets of K Consecutive Numbers_划分数组为连续数字的集合

[Youtube 花花酱](https://youtu.be/7W45U4WLtzg)

- 判断如果元素个数不是 `k` 的倍数则一定无解，返回 `false`
- 用 $BST$ 的 `map` 来存储每个元素出现的频率，是有序的
    `for (int& c : nums) ++m[c];` 时间复杂度为 $O(nlogn)$
- 当 `map` 不为空时：

## 解法一：Map(BST) `find` $O(nlogn)$

- 取出第一个元素数字 `const int x = m.cbegin()->first;`
- 循环，找 `auto it = m.find(x + i)`，如果元素不存在，从 `x` 出发无法构成完整的 `set`，则返回 `false`；否则 `-- it->second` 频率下降，如果频率为 $0$，表示没有这个数了，将 $iterator$ `erase`掉

**时间复杂度**：$O(nlogn)$ + $O(nlogn)$ = $O(nlogn)$

## 解法二：Map(BST) `++iterator` $O(nlogn)$

- 没有必要每次都查找下一个元素，可以用 $iterator$ `++it` 来指向下一个元素
- 只需判断下一个元素是不是想要的元素，如果不是，返回 `false`

**时间复杂度**：$O(nlogn)$ + $O(n)$ = $O(nlogn)$
