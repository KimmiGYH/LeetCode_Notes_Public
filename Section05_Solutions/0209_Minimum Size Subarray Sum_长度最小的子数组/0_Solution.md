# 209_Minimum Size Subarray Sum_长度最小的子数组

这⼀题的解题思路是⽤滑动窗⼝。在滑动窗⼝ `[i,j]`之间不断往后移动，如果总和⼩于 `s`，就扩⼤右边界
`j`，不断加⼊右边的值，直到 `sum > s`，之后再缩⼩ `i` 的左边界，不断缩⼩直到 `sum < s`，这时候右边界
⼜可以往右移动。以此类推。



Huifeng Guang: https://youtu.be/Ucepzsd2A4w

## 关于边界

如果区间为 `[j, i]`，即 `j = -1`，则 `res = i - j + 1;`
如果区间为 `(j, i]`，即 `j = 0`，则 `res = i - j;`
