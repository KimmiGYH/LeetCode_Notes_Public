# 1839_Longest Substring Of All Vowels in Order_所有元音按顺序排布的最长子字符串

## 解法一：双指针


## 解法二：贪心

1.首先如果数组长度小于5的话，不可能满足美丽的定义，将这种情况提前排除

2.遍历时分了几种情况判断：
- 如果前一个字符比当前字符小，那么 `len` +1，元音字母种类也 +1
- 如果前一个字符等于当前字符，那么 `len` +1，元音字母种类不变
- 如果前一个字符比当前字符大，那么肯定当前字串不美丽，以当前字符为首继续进行遍历

3.如果当前子字符串没有以a开头的话，那么在进行下一个子字符串开始遍历之前，元音种类一定不会达到5，所以只要判断种类即可

4.当元音种类为5的时候，持续维护更新最终结果，取出最大值即可


链接：https://leetcode-cn.com/problems/longest-substring-of-all-vowels-in-order/solution/bi-da-xiao-by-sweetpepperj-gdlt/