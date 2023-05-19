# 475_Heaters_供暖器

## 解法一：双指针 $O(m \log m + n \log n)$

- 首先给 $houses$ 和 $heaters$ 两数组排序，以免其为乱序。

    ```
    输入: houses = [1,2,3,4], heaters = [1,4]
    输出: 1
    解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
    ```
- 我们就拿第二个例子来分析，我们的目标是 $houses$ 中的每一个数字都要被cover到，那么我们就遍历 $houses$ 数组，对每一个数组的数字，我们在 $heaters$ 中找能包含这个数字的左右范围，然后看离左右两边谁近取谁的值，

- 如果某个 $houses$ 位置比 $heaters$ 中最小的数字还小，那么肯定要用最小的 $heater$ 去cover，反之如果比最大的数字还大，就用最大的数字去cover。
- 对于每个数字算出的半径，我们要取其中最大的值。

- **算法步骤**：我们在 $heaters$ 中两个数一组进行检查，如果 $abs(heaters[j+1] - houses[i]) <= abs(heaters[j] - houses[i])$，那么我们 $j++$ 继续遍历下一个位置的数。

- 跳出循环的条件是遍历到 $heaters$ 中最后一个数，或者上面的小于等于不成立，此时 $abs(heaters[j] - houses[i])$ 就是能cover当前 $house$ 的最小半径，我们更新结果 $res$ 即可。

**复杂度分析**

- 时间复杂度：$O(m \log m + n \log n)$，其中 $m$ 是数组 $houses$ 的长度，$n$ 是数组 $heaters$ 的长度。
  - 对数组 $houses$ 和 $heaters$ 排序分别需要 $O(m \log m)$ 和 $O(n \log n)$ 的时间。
  - 使用双指针遍历两个数组需要 $O(m + n)$ 的时间。
  - 由于在渐进意义下 $O(m + n)$ 小于 $O(m \log m + n \log n)$，因此总时间复杂度是 $O(m \log m + n \log n)$。

- 空间复杂度：$O(\log m + \log n)$，其中 $m$ 是数组 $houses$ 的长度，$n$ 是数组 $heaters$ 的长度。
  - 空间复杂度主要取决于排序所需要的空间。


## 解法二：排序+二分查找heaters $O((m + n) \log n)$

写法1：
- 用二分查找法来快速找到 $heaters$中 第一个大于等于当前 $house$ 位置的数
- 如果这个数存在，那么我们可以算出其和 $house$ 的差值
- 如果这个数不是 $heaters$ 的首数字而是其他数字，我们可以算出该数字前面一个 $heater$ 数与 $house$ 的差值
- 这两个数中取较小的为cover当前 $house$ 的最小半径，然后我们每次更新结果 $res$ 即可

写法2：
用迭代器和 `lower_bound` 来做

**复杂度分析**

- 时间复杂度：$O((n + m) \log n)$，其中 $m$ 是数组 $houses$ 的长度，$n$ 是数组 $heaters$ 的长度。
  - 对数组 $heaters$ 排序需要 $O(n \log n)$ 的时间。
  - 使用二分查找对每个房屋寻找距离最近的供暖器，每次二分查找需要 $O(\log n)$ 的时间，有 $m$ 个房屋，因此需要 $O(m \log n)$ 的时间。
  - 总时间复杂度是 $O((n + m) \log n)$。

- 空间复杂度：$O(\log n)$，其中 $n$ 是数组 $heaters$ 的长度。
  - 空间复杂度主要取决于排序所需要的空间。

## 解法三：排序+二分查找radius $O(\max(m, n) * \log{L})$

- 需要求得最小加热半径 $radius$，使得所有的 $houses[i]$ 均被覆盖。

- 在以 $radius$ 为分割点的数轴上具有「二段性」：
  - 数值小于 $radius$ 的半径无法覆盖所有的房子；
  - 数值大于等于 $radius$ 的半径可以覆盖所有房子。
- 因此可直接「二分答案」，考虑应该在什么范围内进行「二分」。

- 可以从数据范围入手，使用 $1e9$ 为二分上界，该做法能确保答案在二分范围内。

- 考虑如何实现 `check` 函数。

- 先对 $houses$ 和 $heaters$ 进行排序，使用 $i$ 指向当前处理到的 $houses[i]$；$j$ 指向 **可能** 覆盖到 $houses[i]$ 的最小下标 $heaters[j]$；$radius$ 代表当前需要 `check` 的半径。

- 当 $abs(houses[i] - heaters[j]) > radius$ 时，$houses[i]$ 必然不能被 $heaters[j]$ 所覆盖，此时让 $j$ 自增。

**复杂度分析**

- 时间复杂度：
  - 令 $m$ 和 $n$ 分别为 $houses$ 和 $heaters$ 长度，$L = 1e9$ 为最大长度
  - 对其进行排序复杂度为 $O(m\log{m} + n\log{n})$
  - 在 $[0, L]$ 范围进行二分，单次 `check` 会使用「双指针」判断是否每个 $houses[i]$ 是否被覆盖，复杂度为 $O(\max(m, n) * \log{L})$。
  - 整体复杂度为 $O(\max(m, n) * \log{L})$

- 空间复杂度：排序所需要消耗的空间。复杂度为 $O(\log{m} + \log{n} )$


## 解法三：分块???

```
Example:    h = house,  * = heater  M = INT_MAX

        h   h   h   h   h   h   h   h   h    houses
        1   2   3   4   5   6   7   8   9    index
        *           *       *                heaters
                
        0   2   1   0   1   0   -   -   -    (distance to nearest RHS heater)
        0   1   2   0   1   0   1   2   3    (distance to nearest LHS heater)

        0   1   1   0   1   0   1   2   3    (res = minimum of above two)

Result is maximum value in res, which is 3.
```

