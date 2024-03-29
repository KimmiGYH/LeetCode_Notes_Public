# 395_Longest Substring with At Least K Repeating Characters_至少有 K 个重复字符的最长子串

## 解法一：双指针-滑动窗口

- 这题不具有单调性，不能直接应用滑动窗口求解。
  - 比如
    ```
    |------|--|-----------------|---|------------|
          i-1 i                 j  j+1
    当右端点j往右走，左端点i是否也会往右？并不一定
    比如区间i到j内都是字母b，j+1位置是a，如果左端点i往左移，i-1也为字母a，此时abbbbbbbbbbba的组合也是成立的(k=2时)
    所以这题不具有单调性，不能直接应用双指针滑动窗口
    ```
-  枚举区间中最多包含的不同字符的数量。「当确定了窗口内所包含的字符数量时，区间重新具有了二段性质」。这是本题的滑动窗口解法和迄今为止做的滑动窗口题目的最大不同，本题需要手动增加限制，即限制窗口内字符种类。

- 「为什么需要先枚举 $26$ 种可能性」：
  
  - 因此我们需要先利用字符数量有限性（可枚举）作为切入点，使得「答案子串的左边界左侧的字符以及右边界右侧的字符一定不会出现在子串中」这一性质在双指针的实现下具有单调性。也就是题解说的「让区间重新具有二段性质」。
  
  - 然后遍历 $26$ 种可能性（答案所包含的字符种类数量），对每种可能性应用滑动窗口，可以得到每种可能性的最大值（局部最优），由所有可能性的最大值可以得出答案（全局最优）。
  
  - 当我们使用双指针的时候：
    1. 右端点往右移动必然会导致字符类型数量增加（或不变）
    2. 左端点往右移动必然会导致字符类型数量减少（或不变）

- 当然，我们还需要记录有多少字符符合要求（出现次数不少于 $k$），当区间内所有字符都符合时更新答案。

**算法过程**
- 用哈希表维护两个变量，可以 $O(1)$ 时间维护
  - 不同字符的数量 `tot`
  - 满足要求的字符数量 `sum`
- 对区间进行两种操作：加上字符 或 去掉字符
- 加上字符
  - 判断加之前是 $0$ 次还是 $1$ 次？如 $0$ 次，加完之后就多一个字符 `tot+1`
  - 若加完之后恰好等于要求的最低数量，那么多了一个满足要求的字符 `sum+1`

**复杂度分析**
- 时间复杂度：枚举 $26$ 种可能性，每种可能性会扫描一遍数组。复杂度为 $O(n)$
- 空间复杂度：$O(n)$
