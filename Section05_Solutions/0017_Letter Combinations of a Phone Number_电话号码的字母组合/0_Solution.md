# 17. Letter Combinations of a Phone Number_电话号码的字母组合 (Medium)



## 解法一：递归

**(递归) $O(4^n)$**

1. 可以通过手工或者循环的方式预处理每个数字可以代表哪些字母。
2. 通过递归尝试拼接一个新字母。
3. 递归到目标长度，将当前字母串加入到答案中。
4. 注意，有可能数字串是空串，需要特判。

##### 时间复杂度

由于使用了递归的方式，时间复杂度与答案个数相同。

设数字串长度为 `n`，则最坏时间复杂度为 $O(4^n)$。

外加 `push_back` 答案 需要 `O(n)`的时间复杂度，所以总的时间复杂度为  $O(4^n * n)$


![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0017_Letter%20Combinations%20of%20a%20Phone%20Number_%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88/solve.png)
