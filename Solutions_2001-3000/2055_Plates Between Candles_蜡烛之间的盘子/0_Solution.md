# 2055_Plates Between Candles_蜡烛之间的盘子

### 方法一：前缀和

- 开前缀和数组、表示每个位置的左边第一根蜡烛的数组 l、表示每个位置右边第一根蜡烛的数组 r
- 预处理前缀和数组 `prefix[i] = prefix[i - 1]`
- 从左往右，预处理每个左侧位置的左边第一根蜡烛位置，如果当前不是蜡烛，那默认蜡烛在左边位置 `l[i] = l[i - 1]`，否则是蜡烛则蜡烛位置就是当前位置自己 `l[i] = i`
- 从右往左，预处理每个右侧位置的右边第一根蜡烛位置，如果当前不是蜡烛，那默认蜡烛在右边位置 `r[i] = r[i + 1]`，否则是蜡烛则蜡烛位置就是当前位置自己 `r[i] = i`
- 找到左端点右边第一根蜡烛，以及右端点左边第一根蜡烛
- 记录 `*` 数量的前缀和相减 `prefix[b] - prefix[a - 1]`

**时间复杂度**
- 预处理需要 $O(n)$ 的时间，每个询问仅需要常数的时间，故总时间复杂度为 $O(n+q)$。

**空间复杂度**
- 需要 O(n)O(n) 的额外空间存储预处理的数组。
