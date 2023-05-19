# 374_Guess Number Higher or Lower_猜数字大小 (Easy)

## 解法一：二分

题目中给到的条件是：

$-1$：我选出的数字比你猜的数字小 `pick < num`

$1$：我选出的数字比你猜的数字大 `pick > num`

$0$：我选出的数字和你猜的数字一样。恭喜！你猜对了！`pick == num`

所以如果 $guess(mid) <= 0$ 就说明猜大了，那么右边界压缩，所以 $r = mid$。
