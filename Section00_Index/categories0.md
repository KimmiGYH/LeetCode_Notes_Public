- [Algo 算法题型总结](#algo-算法题型总结)
  - [【一、数据结构】](#一数据结构)
    - [1. C++ STL：](#1-c-stl)
      - [数组](#数组)
      - [栈、队列](#栈队列)
      - [单调栈](#单调栈)
      - [单调队列](#单调队列)
      - [双端队列](#双端队列)
      - [优先队列](#优先队列)
      - [有序集合和映射](#有序集合和映射)
      - [哈希集合和映射](#哈希集合和映射)
    - [2. 字符串：](#2-字符串)
      - [字符串模拟](#字符串模拟)
      - [字符串哈希 Rabin-Karp](#字符串哈希-rabin-karp)
      - [KMP (Knuth-Morris-Pratt)](#kmp-knuth-morris-pratt)
    - [3. 指针结构：](#3-指针结构)
      - [A) 链表](#a-链表)
      - [B) 树](#b-树)
        - [树的递归](#树的递归)
        - [层次遍历](#层次遍历)
        - [前中后序遍历](#前中后序遍历)
        - [二叉查找树](#二叉查找树)
        - [字典树](#字典树)
      - [C) 树与图的DFS和BFS](#c-树与图的dfs和bfs)
    - [4. 并查集](#4-并查集)
    - [5. 复合数据结构](#5-复合数据结构)
      - [树状数组](#树状数组)
      - [AC自动机](#ac自动机)
  - [【二、算法】](#二算法)
    - [6. 双指针问题](#6-双指针问题)
      - [A) 双指针](#a-双指针)
      - [B) 滑动窗口](#b-滑动窗口)
      - [C) 快慢指针](#c-快慢指针)
    - [7. 二分查找](#7-二分查找)
    - [8. 前缀和](#8-前缀和)
    - [9. 排序算法](#9-排序算法)
    - [10. 优先搜索](#10-优先搜索)
      - [深度优先搜索 DFS](#深度优先搜索-dfs)
      - [回溯法](#回溯法)
      - [广度优先搜索 BFS](#广度优先搜索-bfs)
      - [连通分量Floodfill](#连通分量floodfill)
    - [11. 图论](#11-图论)
    - [12. 动态规划](#12-动态规划)
      - [A) 基本一维/二维类型题](#a-基本一维二维类型题)
      - [B) 分割问题](#b-分割问题)
      - [C) 子序列问题](#c-子序列问题)
      - [D) 背包问题](#d-背包问题)
      - [E) 字符串编辑](#e-字符串编辑)
      - [F) 股票交易](#f-股票交易)
    - [13. 分治与递归](#13-分治与递归)
    - [14. 贪心算法](#14-贪心算法)
      - [A) 分配问题](#a-分配问题)
      - [B) 区间类贪心](#b-区间类贪心)
      - [C) 贪心 + 动态规划](#c-贪心--动态规划)
  - [【三、数学】](#三数学)
    - [15. 中学数学](#15-中学数学)
    - [16. 试除法筛素数](#16-试除法筛素数)
    - [18. 位运算](#18-位运算)
    - [19. 数字处理](#19-数字处理)
    - [20. 随机与取样](#20-随机与取样)
  - [----------------](#----------------)
  - [3. 链表](#3-链表)
  - [5. 树](#5-树)
    - [5.2 二叉搜索树](#52-二叉搜索树)
    - [5.3 树的 DFS 和 BFS](#53-树的-dfs-和-bfs)
    - [5.4 综合性DFS题](#54-综合性dfs题)
    - [7.4 逆波兰表达式/计算器表达式求值](#74-逆波兰表达式计算器表达式求值)
    - [7.5 括号序列](#75-括号序列)
  - [11.排序](#11排序)
  - [12.数学](#12数学)
  - [13.搜索](#13搜索)
    - [13.1 DFS](#131-dfs)
    - [13.2 BFS](#132-bfs)
    - [13.3 方向数组](#133-方向数组)
  - [15.分治](#15分治)
  - [16. 动态规划](#16-动态规划)
    - [16.1 路径问题 (数字三角形/矩形)](#161-路径问题-数字三角形矩形)
    - [16.2 Fibonacci 数列](#162-fibonacci-数列)
    - [16.3 字符串上的动态规划](#163-字符串上的动态规划)
    - [16.2 背包问题](#162-背包问题)
      - [16.2.1 01背包](#1621-01背包)
      - [16.2.2 完全背包](#1622-完全背包)
      - [16.2.3 二维费用背包](#1623-二维费用背包)
    - [16.3 子序列/子字符串问题](#163-子序列子字符串问题)
      - [16.3.1 最长上升子序列(LIS模型)](#1631-最长上升子序列lis模型)
      - [16.3.3 最长公共子序列](#1633-最长公共子序列)
      - [16.3.3 线性DP](#1633-线性dp)
      - [抢劫问题](#抢劫问题)
      - [方格取数问题(矩阵双路径)](#方格取数问题矩阵双路径)
      - [股票问题](#股票问题)
      - [表达式匹配](#表达式匹配)
    - [16.4 区间DP](#164-区间dp)
    - [16.5 树形DP](#165-树形dp)
    - [16.6 记忆化搜索](#166-记忆化搜索)
    - [16.7 状态机DP](#167-状态机dp)
    - [16.8 状压DP](#168-状压dp)
    - [16.9 最短路动态规划](#169-最短路动态规划)
  - [18.树状数组](#18树状数组)
  - [19.蓄水池抽样](#19蓄水池抽样)
  - [20. 综合题](#20-综合题)

# Algo 算法题型总结



## 【一、数据结构】

### 1. C++ STL：

#### 数组

**数组模拟+进位**

- [ ] [LeetCode 66_Plus One_加一](https://leetcode.com/problems/plus-one/)（数组+进位）
- [ ] 
- [ ] [LeetCode 2022_Convert 1D Array Into 2D Array_将一维数组转变成二维数组](https://leetcode.com/problems/convert-1d-array-into-2d-array/)（数组，一维->二维）
- [ ] [LeetCode 495_Teemo Attacking_提莫攻击](https://leetcode.com/problems/teemo-attacking/)（数组模拟 + 贪心）
- [ ] [LeetCode 717_1-bit and 2-bit Characters_1比特与2比特字符](https://leetcode.com/problems/1-bit-and-2-bit-characters/)（数组模拟 + 贪心）
- [ ] [LeetCode 794_Valid Tic-Tac-Toe State_有效的井字游戏](https://leetcode.com/problems/valid-tic-tac-toe-state/)（二维数组模拟）
- [ ] LeetCode 519_Random Flip Matrix_随机翻转矩阵（哈希表+二维矩阵->一维 + 随机）
- [ ] [LeetCode 36_Valid Sudoku_有效的数独](https://leetcode.com/problems/valid-sudoku/)（数组+位操作）
- [ ] [LeetCode 48_Rotate Image_旋转图像](https://leetcode.com/problems/rotate-image/)（二维数组原地旋转）
- [ ] [LeetCode189_Rotate Array_旋转数组](https://leetcode.com/problems/rotate-array/)
- [ ] 
- [ ] [LeetCode 57_Insert Interval_插入区间](https://leetcode.com/problems/insert-interval/)（区间问题）
- [ ] [LeetCode 73_Set Matrix Zeroes_矩阵置零](https://leetcode.com/problems/set-matrix-zeroes/)
- [总结] lc169 和 lc面试题考点一样，摩尔投票法
- [ ] [LeetCode 169_Majority Element_多数元素](https://leetcode.com/problems/majority-element/)（摩尔投票法）
- [ ] [LeetCode 面试题 17.10. 主要元素](https://leetcode-cn.com/problems/find-majority-element-lcci/)（摩尔投票法）
- [ ] [LeetCode 229_Majority Element II_求众数 II](https://leetcode.com/problems/majority-element-ii/)（摩尔投票法）
- [ ] [LeetCode 238_Product of Array Except Self_除自身以外数组的乘积](https://leetcode.com/problems/product-of-array-except-self/)（前后缀分解/前缀积后缀积）
- [ ] [LeetCode 384_Shuffle an Array_打乱数组](https://leetcode.com/problems/shuffle-an-array/)（洗牌算法）
- [总结] acw797 和 lc413 都是差分
- [ ] [AcWing 797. 差分](https://www.acwing.com/activity/content/problem/content/831/1/)（差分）
- [ ] [LeetCode 413_Arithmetic Slices_等差数列划分](https://leetcode.com/problems/arithmetic-slices/)（双指针+差分+DP）
- [ ] LeetCode419.甲板上的战舰
- [ ] LeetCode442.数组中重复的数据（内卷法）
- [ ] LeetCode448.找到所有数组中消失的数字（内卷法）
- [ ] LeetCode453.最小移动次数使数组元素相等（逆向思维）
- [ ] LeetCode561.数组拆分Ⅰ
- [ ] LeetCode565.数组嵌套（数组模拟图）
- [ ] LeetCode566.重塑矩阵（坐标变换）
- [ ] LeetCode1491.去掉最低工资和最高工资后的平均值（模拟）
- [ ] LeetCode1550.存在连续三个奇数的数组
- [ ] LeetCode1675.使数组互补的最少操作次数（一维差分）

#### 栈、队列

**栈**

- [总结] 栈模板题
- [ ] [LeetCode 20. Valid Parentheses_有效的括号](https://leetcode.com/problems/valid-parentheses/)（栈+哈希表+ASCII）
- [ ] [LeetCode 155_Min Stack_最小栈](https://leetcode.com/problems/min-stack/)（栈+递推）
- [ ] [LeetCode 682_Baseball Game_棒球比赛](https://leetcode.com/problems/baseball-game/)（栈）

- [总结] 栈思想的字符串操作
- [ ] [LeetCode 1047_Remove All Adjacent Duplicates In String_删除字符串中的所有相邻重复项](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)（字符串+栈思想）
- [ ] [LeetCode 844_Backspace String Compare_比较含退格的字符串](https://leetcode.com/problems/backspace-string-compare/)（字符串+栈思想+双指针）
- [ ] [LeetCode 1209_Remove All Adjacent Duplicates in String II_删除字符串中的所有相邻重复项 II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)（字符串+栈）

- [ ] LeetCode 1381.设计一个支持增量操作的栈（设计）

- [总结] 栈与队列的相互转换
- [ ] [LeetCode 232_Implement Queue using Stacks_用栈实现队列](https://leetcode.com/problems/implement-queue-using-stacks/)（栈+队列）
- [ ] [LeetCode 225_Implement Stack using Queues_用栈实现队列](https://leetcode.com/problems/implement-stack-using-queues/)（队列+栈）

- [总结] 设计题，复合数据结构，栈+哈希表

- [ ] [LeetCode 895_H_Maximum Frequency Stack_最大频率栈](https://leetcode.com/problems/maximum-frequency-stack/)（Hard+设计+哈希表+栈）

- [总结] 栈与表达式：逆波兰表达式/计算器
- [ ] [LeetCode 150_Evaluate Reverse Polish Notation_逆波兰表达式求值](https://leetcode.com/problems/evaluate-reverse-polish-notation/)（栈+后缀表达式+后序遍历）
- [ ] [AcWing 3302. 表达式求值](https://www.acwing.com/activity/content/code/content/2440506/)（模板题）
- [ ] [LeetCode 227_Basic Calculator II_基本计算器 II](https://leetcode.com/problems/basic-calculator-ii/)（栈+表达式求值+加减乘除/空格）
- [ ] [LeetCode 224_H_Basic Calculator_基本计算器](https://leetcode.com/problems/basic-calculator/) （栈+表达式求值+加减乘除/空格/特殊符号）
- [ ] [LeetCode 1190_Reverse Substrings Between Each Pair of Parentheses_反转每对括号间的子串](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)（栈+预处理括号-做不来）
- [ ] [LeetCode 394_Decode String_字符串解码](https://leetcode.com/problems/decode-string/)（栈+表达式求值+递归）

- [总结] 栈与贪心/栈与括号
- [LeetCode 921_Minimum Add to Make Parentheses Valid_使括号有效的最少添加](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)（字符串+括号+贪心）
- [LeetCode 1541_Minimum Insertions to Balance a Parentheses String_平衡括号字符串的最少插入次数](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)（栈+字符串+括号+贪心）


**队列**
- [总结] 循环队列和双端队列
- [ ] [LeetCode 622_Design Circular Queue_设计循环队列](https://leetcode.com/problems/design-circular-queue/)（循环队列）
- [ ] [LeetCode 641_Design Circular Deque_设计循环双端队列](https://leetcode.com/problems/design-circular-deque/)（双端队列）

- [总结] 队列与贪心
- [ ] [LeetCode 649_Dota2 Senate_Dota2 参议院](https://leetcode.com/problems/dota2-senate/)（队列 + 贪心）

#### 单调栈

- [ ] [AcWing 830. 单调栈](https://www.acwing.com/activity/content/problem/content/867/1/)（模板题）
- [ ] [LeetCode 496_Next Greater Element I_下一个更大元素 I](https://leetcode.com/problems/next-greater-element-i)（单调栈+哈希表）
- [ ] [LeetCode 503_Next Greater Element II_下一个更大元素 II](https://leetcode.com/problems/next-greater-element-ii)（单调栈+循环数组）
- [ ] [LeetCode 1996_The Number of Weak Characters in the Game_游戏中弱角色的数量](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/)（单调栈+lambda）
- [ ] [LeetCode 42_Trapping Rain Water_接雨水(Hard)](https://leetcode.com/problems/trapping-rain-water/) （单调栈+双指针）
- [ ] [LeetCode 84_H_Largest Rectangle in Histogram_柱状图中最大的矩形](https://leetcode.com/problems/largest-rectangle-in-histogram/)（Hard+单调递增栈）
- [ ] LeetCode 85.最大矩形（84拓展）
- [ ] [LeetCode 739_Daily Temperatures_每日温度](https://leetcode.com/problems/daily-temperatures/)
- [ ] 





#### 单调队列

- [ ] LeetCode 239.滑动窗口最大值
- [ ] [LeetCode 1438_Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit_绝对差不超过限制的最长连续子数组](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)（滑动窗口+multiset+单调队列）

#### 双端队列

- [ ] 
- [ ] 


#### 优先队列

- [ ] [LeetCode 215_Kth Largest Element in an Array_数组中的第K个最大元素](https://leetcode.com/problems/kth-largest-element-in-an-array/)（TopK）（快速排序+堆）
- [ ] [LeetCode 295_Find Median from Data Stream_数据流的中位数](https://leetcode.com/problems/find-median-from-data-stream/)（对顶堆）
- [ ] [LeetCode 480_Sliding Window Median_滑动窗口中位数](https://leetcode.com/problems/sliding-window-median/)（对顶堆+multiset+优先队列+滑动窗口）
- [ ] LeetCode 347.前K个高频元素（TopK）
- [ ] LeetCode 373.查找和最小的K对数字（TopK）
- [ ] LeetCode 451.根据字符出现频率排序（TopK）
- [ ] [LeetCode 767_Reorganize String_重构字符串](https://leetcode.com/problems/reorganize-string/)（贪心+优先队列+堆）
- [ ] [LeetCode 692_Top K Frequent Words_前K个高频单词](https://leetcode.com/problems/top-k-frequent-words/)（优先队列+堆排序&set自动排序+桶排序）
- [ ] [LeetCode 786_K-th Smallest Prime Fraction_第 K 个最小的素数分数](https://leetcode.com/problems/k-th-smallest-prime-fraction/)（自定义排序+优先队列+二分查找+双指针）
- [ ] [LeetCode 355_M_Design Twitter_设计推特](https://leetcode.com/problems/design-twitter/)（设计+哈希表+优先队列）
- [ ] [LeetCode 2034_Stock Price Fluctuation_股票价格波动](https://leetcode.com/problems/stock-price-fluctuation/)（multiset+hashmap+优先队列+template）



#### 有序集合和映射

- [ ] [LeetCode 575_Distribute Candies_分糖果](https://leetcode.com/problems/distribute-candies/)（set）
- [ ] [LeetCode_1296_Divide Array in Sets of K Consecutive Numbers_划分数组为连续数字的集合](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/)（map）
- [ ] [LeetCode 220_Contains Duplicate III_存在重复元素Ⅲ](https://leetcode.com/problems/contains-duplicate-iii/)（multiset+滑动窗口+lower_bound+绝对值+迭代器）
- [ ] [LeetCode 480_Sliding Window Median_滑动窗口中位数](https://leetcode.com/problems/sliding-window-median/)（对顶堆+multiset+优先队列+滑动窗口）
- [ ] [LeetCode 1438_Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit_绝对差不超过限制的最长连续子数组](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)（滑动窗口+multiset+单调队列）
- [ ] [LeetCode 2034_Stock Price Fluctuation_股票价格波动](https://leetcode.com/problems/stock-price-fluctuation/)（multiset+hashmap+优先队列+template）

#### 哈希集合和映射

- [总结] 模板题
- [ ] [LeetCode 2150_E_Find All Lonely Numbers in the Array_找出数组中的所有孤独数字](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/)（哈希表）
- [ ] [LeetCode E_383_Ransom Note_赎金信](https://leetcode.com/problems/ransom-note/)（哈希表）
- [ ] [LeetCode 645_E_Set Mismatch_错误的集合](https://leetcode.com/problems/set-mismatch)（分组异或+哈希表）
- [ ] [LeetCode 748_E_Shortest Completing Word_最短补全词](https://leetcode.com/problems/shortest-completing-word/)（哈希表）
- [总结] 带点技巧的哈希
- [ ] [LeetCode 1365_How Many Numbers Are Smaller Than the Current Number_有多少小于当前数字的数字](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)（哈希表+前缀和+计数排序+二分）
- [总结] 罗马数字
- [ ] [LeetCode 13_E_Roman to Integer_罗马数字转整数](https://leetcode.com/problems/roman-to-integer/)（哈希表）
- [ ] [LeetCode 12_Integer to Roman_整数转罗马数字](https://leetcode.com/problems/integer-to-roman/)（pair+哈希思维）
- [ ] [LeetCode 781_Rabbits in Forest_森林中的兔子](https://leetcode.com/problems/rabbits-in-forest/)（思维题+哈希表+上取整）
- [ ] [LeetCode 500_E_Keyboard Row_键盘行](https://leetcode.com/problems/keyboard-row/)（哈希表，Set）
- [ ] [Leetcode 594_E_Longest Harmonious Subsequence_最长和谐子序列](https://leetcode.com/problems/longest-harmonious-subsequence/)（哈希表+双指针）
- [ ] [LeetCode 791_Custom Sort String_自定义字符串排序](https://leetcode.com/problems/custom-sort-string/)（哈希表+数组映射+lambda）
- [总结] 字母异位词
- [ ] [LeetCode 49_Group Anagrams_字母异位词分组](https://leetcode.com/problems/group-anagrams/)（Anagram+哈希表+排序+数组映射+lambda）
- [ ] 
- [ ] [LeetCode 187_Repeated DNA Sequences_重复的DNA序列](https://leetcode.com/problems/repeated-dna-sequences/)（哈希表+字符串哈希+滑动窗口+二进制位存状态）
- [ ] LeetCode 128.最长连续序列
- [总结] 存在重复元素系列
- [ ] [LeetCode 217_Contains Duplicate_存在重复元素](https://leetcode.com/problems/contains-duplicate/)（哈希表）
- [ ] [LeetCode 219_Contains Duplicate II_存在重复元素Ⅱ](https://leetcode.com/problems/contains-duplicate-ii/)（哈希表+滑动窗口）
- [ ] [LeetCode 220_Contains Duplicate III_存在重复元素Ⅲ](https://leetcode.com/problems/contains-duplicate-iii/)（Set+滑动窗口+lower_bound）
- [ ] LeetCode 299.猜数字游戏
- [ ] LeetCode 349.两个数组的交集
- [ ] LeetCode 350.两个数组的交集Ⅱ
- [ ] LeetCode 380.常数时间插入、删除和获取随机元素
- [ ] LeetCode 381.O(1)时间插入、删除和获取随机元素-允许重复
- [ ] LeetCode 387.字符中的第一个唯一字符
- [ ] LeetCode 409.最长回文串
- [ ] LeetCode 437.路径总和Ⅲ（前缀和+哈希表）
- [ ] LeetCode 454.四数相加Ⅱ
- [ ] LeetCode 560.和为K的子数组（前缀和+哈希表）
- [ ] LeetCode 454.四数相加Ⅱ
- [ ] LeetCode 146.LRU缓存
- [ ] LeetCode 460.LFU缓存
- [ ] LeetCode 523.连续子数组和（前缀和+哈希表）
- [ ] LeetCode 532.数组中的k-diff数对
- [ ] [LeetCode 554_Brick Wall_砖墙](https://leetcode.com/problems/brick-wall/)（哈希表）
- [ ] LeetCode 705.设计哈希集合
- [ ] LeetCode 706.设计哈希映射
- [ ] LeetCode 1577.数的平方等于两数乘积的方法数
- [ ] LeetCode 1604.警告一小时内使用相同员工卡大于等于3次的人（哈希表，排序）
- [ ] LeetCode 1647.字符频次唯一的最小删除次数
- [ ] LeetCode 1679.K和数对的最小数目（哈希表/双指针）
- [总结] 两个哈希表比较有效字符（直接看滑动窗口类别里整理的题）
- [ ] [LeetCode 76_H_Minimum Window Substring_最小覆盖子串](https://leetcode.com/problems/minimum-window-substring/)（两个哈希表）
- [ ] [LeetCode 30_H_Substring with Concatenation of All Words_串联所有单词的子串](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)（滑动窗口+两个哈希表）
- [总结] 求区间和，用前缀和+哈希表
- [ ] [LeetCode 560_Subarray Sum Equals K_和为K的子数组](https://leetcode.com/problems/subarray-sum-equals-k)（一维前缀和+区间和+哈希表）
- [ ] [LeetCode 1074_H_Number of Submatrices That Sum to Target_元素和为目标值的子矩阵数量](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)（二维前缀和+区间和+哈希表）
- [ ] [LeetCode 1711_Count Good Meals_大餐计数](https://leetcode.com/problems/count-good-meals/)（哈希表+区间和思想）
- [总结] 较难题
- [ ] [LeetCode 202_Happy Number_快乐数](https://leetcode.com/problems/happy-number/)（HashSet + 快慢指针+龟兔赛跑Floyd's Cycle）
- [ ] [LeetCode 149_H_Max Points on a Line_直线上最多的点数](https://leetcode.com/problems/max-points-on-a-line/description/)（哈希表）
- [总结] 设计题
- [ ] [LeetCode 2034_Stock Price Fluctuation_股票价格波动](https://leetcode.com/problems/stock-price-fluctuation/)（multiset+hashmap+优先队列+template）
- [ ] [LeetCode 355_M_Design Twitter_设计推特](https://leetcode.com/problems/design-twitter/)（设计+哈希表+优先队列）

### 2. 字符串：

#### 字符串模拟

- [ ] [LeetCode 1047_Remove All Adjacent Duplicates In String_删除字符串中的所有相邻重复项](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)（字符串+栈思想）
- [ ] [LeetCode 844_Backspace String Compare_比较含退格的字符串](https://leetcode.com/problems/backspace-string-compare/)（字符串+栈思想+双指针）
- [ ] 
- [ ] [LeetCode 1816_Truncate Sentence_截断句子](https://leetcode.com/problems/truncate-sentence/)（字符串模拟）
- [ ] [AcWing 445. 数字反转](https://www.acwing.com/activity/content/code/content/1884278/)（高精度+数学+秦九韶算法+字符串模拟）
- [ ] 


#### 字符串哈希 Rabin-Karp

- [ ] [AcWing 841. 字符串哈希](https://www.acwing.com/activity/content/code/content/741461/)
- [ ] [LeetCode 28_Implement strStr()_实现 strStr()](https://leetcode.com/problems/implement-strstr/)（KMP + 字符串哈希）
- [ ] [LeetCode 139_Word Break_单词拆分](https://leetcode.com/problems/word-break/)（DP+字符串哈希）
- [ ] [LeetCode 187_Repeated DNA Sequences_重复的DNA序列](https://leetcode.com/problems/repeated-dna-sequences/)（哈希表+字符串哈希+滑动窗口+二进制位存状态）
- [ ] [LeetCode 30_H_Substring with Concatenation of All Words_串联所有单词的子串](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)（Hard，哈希表+滑动窗口+字符串哈希）

#### KMP (Knuth-Morris-Pratt)

- [ ] [AcWing 831. KMP字符串](https://www.acwing.com/file_system/file/content/whole/index/content/2174696/)（KMP）
- [ ] [LeetCode 28_Implement strStr()_实现 strStr()](https://leetcode.com/problems/implement-strstr/)（KMP + 字符串哈希）

**其他**

- [ ] [LeetCode 5_Longest Palindromic Substring_最长回文子串](https://leetcode.com/problems/longest-palindromic-substring/)（DP + 中心扩展法）
- [ ] LeetCode 520.检测大写字母（模拟）
- [ ] LeetCode 521.最长特殊序列1（脑筋急转弯）
- [ ] LeetCode 522.最长特殊序列2（双指针判定子序列）
- [ ] LeetCode 551.学生出勤记录1
- [ ] LeetCode 647.回文子串（中心扩展法）
- [ ] LeetCode 1332.删除回文子序列（脑筋急转弯）
- [ ] LeetCode 1637.统计只差一个字符的子串数目（暴力枚举）


### 3. 指针结构：

#### A) 链表



#### B) 树

##### 树的递归

##### 层次遍历

##### 前中后序遍历

##### 二叉查找树

- [总结] 二分搜索树 BST
- [ ] [LeetCode 653_Two Sum IV - Input is a BST_两数之和 IV - 输入 BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)（BST中序遍历+DFS+BFS+Hashet）


##### 字典树

- [ ] [LeetCode 208_Implement Trie (Prefix Tree)_实现 Trie (前缀树)](https://leetcode.com/problems/implement-trie-prefix-tree/)（Trie树）
- [ ] [LeetCode 211_Design Add and Search Words Data Structure_添加与搜索单词-数据结构设计](https://leetcode.com/problems/design-add-and-search-words-data-structure/)（Trie树+DFS）
- [ ] LeetCode 212.单词搜索Ⅱ（DFS+Trie优化）
- [ ] LeetCode 421.数组中两个数的最大异或值

#### C) 树与图的DFS和BFS

- [ ] [LeetCode 1743_Restore the Array From Adjacent Pairs_从相邻元素对还原数组](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/) （哈希表+无向树+建图+邻接表+DFS+BFS）


### 4. 并查集

### 5. 复合数据结构

#### 树状数组

- [ ] [LeetCode 307_M_Range Sum Query - Mutable_区域和检索 - 数组可修改](https://leetcode.com/problems/range-sum-query-mutable/)（树状数组模板题）
- [ ] [LeetCode 406_M_Queue Reconstruction by Height_根据身高重建队列](https://leetcode.com/problems/queue-reconstruction-by-height/)（贪心 + 树状数组 + 二分）
- [ ] 315 Count of Smaller Numbers After Self
- [ ] 493 Reverse Pairs 
- [ ] 649 Created Sorted Array through Instructions
- [ ] [LeetCode 1310_XOR Queries of a Subarray_子数组异或查询](https://leetcode.com/problems/xor-queries-of-a-subarray)（树状数组 + 前缀异或）

#### AC自动机
- [ ] [1032]

## 【二、算法】

- [总结] 上取整的技巧：$\left \lceil \frac{a}{b}  \right \rceil = \left \lfloor \frac{a + b - 1}{b}\right \rfloor$
- [ ]  #781 #875  #1283 #1760  #2064



### 6. 双指针问题

#### A) 双指针

**A1 同向双指针**

- [ ] [LeetCode 1446_E_Consecutive Characters_连续字符](https://leetcode.com/problems/consecutive-characters/)（双指针）
- [ ] [LeetCode 485_E_Max Consecutive Ones_最大连续 1 的个数](https://leetcode.com/problems/max-consecutive-ones/)（双指针）
- [ ] [LeetCode 524_M_Longest Word in Dictionary through Deleting_通过删除字母匹配到字典里最长单词](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)（判断子序列+双指针）
- [ ] [LeetCode 1764_Form Array by Concatenating Subarrays of Another Array_通过连接另一个数组的子数组得到一个数组](https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/)（判断子序列+双指针）
- [ ] [LeetCode 26_E_Remove Duplicates from Sorted Array_删除排序数组中的重复项](https://leetcode.com/problems/remove-duplicates-from-sorted-array)（双指针）
- [ ] [LeetCode 80_M_Remove Duplicates from Sorted Array II_删除排序数组中的重复项 II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)（双指针）
- [ ] [LeetCode 27_Remove Element_移除元素](https://leetcode.com/problems/remove-element/)（同向+逆向双指针）
- [ ] [LeetCode 88_E_Merge Sorted Array_合并两个有序数组](https://leetcode.com/problems/merge-sorted-array/)（双指针 + 归并）
- [ ] [LeetCode 45_H_Jump Game II 跳跃游戏 II](https://leetcode.com/problems/jump-game-ii/)（双指针+贪心+单调性）
- [ ] [LeetCode 413_M_Arithmetic Slices_等差数列划分](https://leetcode.com/problems/arithmetic-slices/)（双指针+差分+DP）
- [ ] [LeetCode 443_M_String Compression_压缩字符串](https://leetcode.com/problems/string-compression/)（双指针+秦九韶）
- [ ] [LeetCode 581_M_Shortest Unsorted Continuous Subarray_最短无序连续子数组](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)（双指针）
- [ ] [LeetCode 475_M_Heaters_供暖器](https://leetcode.com/problems/heaters/)（双指针+索引二分+值域二分）
- [ ] [LeetCode 930_M_Binary Subarrays With Sum_和相同的二元子数组](https://leetcode.com/problems/binary-subarrays-with-sum/)（前缀和+双指针+滑动窗口）
- [ ] [LeetCode 786_K-th Smallest Prime Fraction_第 K 个最小的素数分数](https://leetcode.com/problems/k-th-smallest-prime-fraction/)（自定义排序+优先队列+二分查找+双指针）
- [ ] [LeetCode 844_Backspace String Compare_比较含退格的字符串](https://leetcode.com/problems/backspace-string-compare/)（字符串+栈思想+双指针）
- [ ] LeetCode 38.外观数列
- [ ] LeetCode 58.最后一个单词长度
- [ ] LeetCode 80.删除排序数组中的重复项Ⅱ
- [ ] LeetCode 75.颜色分类（三指针）
- [ ] LeetCode 283.移动零
- [ ] LeetCode 392.判断子序列
- [ ] LeetCode 434.字符串中的单词数
- [ ] LeetCode 763.划分字母区间
- [ ] LeetCode 922.按奇偶排序数组
- [ ] LeetCode 986.区间列表的交集
- [ ] 

**A2 逆向双指针**

- [ ] [LeetCode 345_Reverse Vowels of a String_反转字符串中的元音字母](https://leetcode.com/problems/reverse-vowels-of-a-string/)（逆向双指针）
- [ ] [LeetCode 27_Remove Element_移除元素](https://leetcode.com/problems/remove-element/)（同向+逆向双指针）
- [ ] [LeetCode 633_Sum of Square Numbers_方数之和](https://leetcode.com/problems/sum-of-square-numbers/)（逆向双指针）
- [ ] [LeetCode 832_Flipping an Image_翻转图像](https://leetcode.com/problems/flipping-an-image)（逆向双指针+异或切换）
- [ ] [LeetCode 1750_Minimum Length of String After Deleting Similar Ends_删除字符串两端相同字符后的最短长度](https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/)
- [ ] [LeetCode 11_M_Container With Most Water_盛最多水的容器](https://leetcode.com/problems/container-with-most-water/)（双指针+贪心）
- [ ] [LeetCode 881_M_Boats to Save People_救生艇](https://leetcode.com/problems/boats-to-save-people/)（双指针+贪心）
- [ ] LeetCode 5.最长回文子串
- [总结] 2Sum两数之和变种题
- [ ] [LeetCode 167_E_Two Sum II - Input array is sorted_两数之和 II - 输入有序数组](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)（双指针 + 二分）
- [ ] [LeetCode 15_3Sum_三数之和](https://leetcode.com/problems/3sum/)（双指针）
- [ ] [LeetCode 259_$_较小的三数之和](https://leetcode-cn.com/problems/3sum-smaller/)（双指针）
- [ ] [LeetCode 16_最接近的三数之和](https://leetcode.com/problems/3sum-closest/)（双指针）
- [ ] [LeetCode 18_4Sum_四数之和](https://leetcode.com/problems/4sum/)（双指针）
- [ ] [LeetCode 611_Valid Triangle Number_有效三角形的个数](https://leetcode.com/problems/valid-triangle-number/)（双指针+二分）
- [ ] [LeetCode 825_Friends Of Appropriate Ages_适龄的朋友](https://leetcode.com/problems/friends-of-appropriate-ages/)（双指针+桶排序）
- [ ] LeetCode 125.验证回文串
- [ ] LeetCode 344.反转字符串
- [ ] LeetCode 345.反转字符串中的元音字母

#### B) 滑动窗口

- [ ] [Leetcode 594_E_Longest Harmonious Subsequence_最长和谐子序列](https://leetcode.com/problems/longest-harmonious-subsequence/)（哈希表+双指针）
- [ ] [LeetCode 643_E_Maximum Average Subarray I_子数组最大平均数 I](https://leetcode.com/problems/maximum-average-subarray-i/)（滑动窗口）
- [ ] [LeetCode 1423_Maximum Points You Can Obtain from Cards_可获得的最大点数](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)（滑动窗口）
- [ ] [LeetCode 1052_M_Grumpy Bookstore Owner_爱生气的书店老板](https://leetcode.com/problems/grumpy-bookstore-owner/)（滑动窗口）
- [ ] [LeetCode 1208_Get Equal Substrings Within Budget_尽可能使字符串相等](https://leetcode.com/problems/get-equal-substrings-within-budget/)（滑动窗口）
- [ ] [LeetCode 1438_Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit_绝对差不超过限制的最长连续子数组](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)（滑动窗口+multiset+单调队列）
- [ ] [LeetCode 1610_H_Maximum Number of Visible Points_可见点的最大数目](https://leetcode.com/problems/maximum-number-of-visible-points/)（滑动窗口+二分查找）
- [总结] 最长连续 1 的个数，转换思路
- [ ] [LeetCode 1004_Max Consecutive Ones III_最大连续1的个数 III](https://leetcode.com/problems/max-consecutive-ones-iii/)（双指针+滑动窗口）
- [ ] [LeetCode 2134_Minimum Swaps to Group All 1's Together II_最少交换次数来组合所有的 1 II](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/)（双指针+滑动窗口）
- [总结] 最长不重复子序列问题+有效字符
- [ ] [LeetCode 3_M_Longest Substring Without Repeating Characters_无重复字符的最长子串](https://leetcode.com/problems/longest-substring-without-repeating-characters/)（滑动窗口）
- [ ] [LeetCode 438_M_Find All Anagrams in a String_找到字符串中所有字母异位词](https://leetcode.com/problems/longest-repeating-character-replacement/)（哈希表滑动窗口）
- [ ] [LeetCode 567_Permutation in String_字符串的排列](https://leetcode.com/problems/permutation-in-string/)（哈希表+滑动窗口 和438一模一样）
- [ ] [LeetCode 76_H_Minimum Window Substring_最小覆盖子串](https://leetcode.com/problems/minimum-window-substring/)（两个哈希表+有效字符）
- [ ] [LeetCode 30_H_Substring with Concatenation of All Words_串联所有单词的子串](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)（Hard，哈希表+滑动窗口+字符串哈希）
- [ ] [LeetCode 930_M_Binary Subarrays With Sum_和相同的二元子数组](https://leetcode.com/problems/binary-subarrays-with-sum/)（前缀和+双指针+滑动窗口）
- [总结]至多包含 k 个不同字符的最长子串 lc159, lc340, lc992 
- [ ] [LeetCode 159_$_至多包含两个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/)（滑动窗口+哈希表）
- [ ] [LeetCode 340_$_至多包含 K 个不同字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-most-k-distinct-characters/)（滑动窗口+哈希表）
- [ ] [LeetCode 992_H_Subarrays with K Different Integers_K 个不同整数的子数组](https://leetcode.com/problems/subarrays-with-k-different-integers/)（与930类似滑动窗口）
- [ ] 
- [ ] [LeetCode 1838_Frequency of the Most Frequent Element_最高频元素的频数](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)（前缀和+滑动窗口+二分）
- [总结] 枚举26个字符的滑动窗口题目lc395, lc424
- [ ] [LeetCode 395_M_Longest Substring with At Least K Repeating Characters_至少有 K 个重复字符的最长子串](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/)（双指针+单调性）
- [ ] [LeetCode 424_M_Longest Repeating Character Replacement_替换后的最长重复字符](https://leetcode.com/problems/longest-repeating-character-replacement/)（滑动窗口）
- [ ] LeetCode 209.长度最小的子数组（前缀和+双指针）
- [ ] LeetCode 532.数组中的k-diff数对
- [ ] LeetCode 567.字符串的排列
- [ ] LeetCode 1004.最大连续1的个数Ⅲ
- [ ] LeetCode 1493.删掉一个元素以后全为1的最长子数组
- [ ] LeetCode 1695.删除子数组的最大得分（哈希表+滑动窗口）

#### C) 快慢指针

- [ ] [LeetCode 19_Remove Nth Node From End of List 删除链表的倒数第N个节点](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)（链表+快慢指针）
- [总结] lc142 和 lc287 都可以用龟兔赛跑 Floyd's Cycle的算法
- [ ] [LeetCode 141_Linked List Cycle_环形链表](https://leetcode.com/problems/linked-list-cycle/)（快慢指针）
- [ ] [LeetCode 142_Linked List Cycle II_环形链表Ⅱ](https://leetcode.com/problems/linked-list-cycle-ii/)（快慢指针+龟兔赛跑Floyd's Cycle）
- [ ] [LeetCode 202_Happy Number_快乐数](https://leetcode.com/problems/happy-number/)（HashSet + 快慢指针+龟兔赛跑Floyd's Cycle）
- [ ] [LeetCode 287_Find the Duplicate Number_寻找重复数](https://leetcode.com/problems/find-the-duplicate-number/)（鸽巢原理+值域二分+龟兔赛跑Floyd's Cycle + 位操作）

### 7. 二分查找

- [总结] 二分模板题
- [ ] [LeetCode 704_Binary Search_二分查找](https://leetcode.com/problems/binary-search/)（二分模板题）
- [ ] [LeetCode 278_First Bad Version_第一个错误的版本](https://leetcode.com/problems/first-bad-version/submissions/)（二分模板）
- [ ] [AcWing 789. 数的范围](https://www.acwing.com/file_system/file/content/whole/index/content/1721187/)
- [ ] [LeetCode 34_Find First and Last Position of Element in Sorted Array_在排序数组中查找元素的第一个和最后一个位置](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
- [ ] [LeetCode 1365_How Many Numbers Are Smaller Than the Current Number_有多少小于当前数字的数字](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)（哈希表+前缀和+计数排序+二分）
- [总结 ] 注意**边界**问题，当最后一个位置也可以插入时，`r=n`;
- [ ] [LeetCode 35_Search Insert Position_搜索插入位置](https://leetcode.com/problems/search-insert-position/)（索引二分+边界问题）
- [ ] [LeetCode 1818_Minimum Absolute Sum Difference_绝对差值和](https://leetcode.com/problems/minimum-absolute-sum-difference/)（索引二分+边界问题）
- [ ] [LeetCode 1539_Kth Missing Positive Number_第 k 个缺失的正整数](https://leetcode.com/problems/kth-missing-positive-number/)（暴力+思维+二分+边界问题）
- [总结] **旋转**排序数组，体现了二分的本质是**分段性**而非单调性
- [ ] [LeetCode 852_Peak Index in a Mountain Array_山脉数组的峰顶索引](https://leetcode.com/problems/peak-index-in-a-mountain-array/)（二分的分段性）
- [ ] [LeetCode 162_Find Peak Element_寻找峰值](https://leetcode.com/problems/find-peak-element/)（二分的分段性，和852一样）
- [ ] [LeetCode 33_Search in Rotated Sorted Array_搜索旋转排序数组](https://leetcode.com/problems/search-in-rotated-sorted-array/)（二分的分段性）
- [ ] [LeetCode 81_Search in Rotated Sorted Array II_搜索旋转排序数组Ⅱ](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)（二分的分段性）
- [ ] [LeetCode 153_Find Minimum in Rotated Sorted Array_寻找旋转排序数组中的最小值](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)（二分的分段性）
- [ ] [LeetCode 154_Find Minimum in Rotated Sorted Array II_寻找旋转排序数组中的最小值Ⅱ](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)（二分的分段性，综合153+81）
- [总结] **二维矩阵**中的二分查找 lc74, lc240
- [ ] [LeetCode 74_Search a 2D Matrix_搜索二维矩阵](https://leetcode.com/problems/search-a-2d-matrix/)（经典！坐标变换：二维到一维+二分）
- [ ] [LeetCode 240_Search a 2D Matrix II_搜索二维矩阵 II](https://leetcode.com/problems/search-a-2d-matrix-ii/)
- [总结] **综合**练习 lc274 是 lc275的铺垫，lc275练习二分
- [ ] [LeetCode 274_H-Index_H指数](https://leetcode.com/problems/h-index/)（排序）
- [ ] [LeetCode 275_H-Index II_H指数Ⅱ](https://leetcode.com/problems/h-index-ii/)（二分）
- [ ] [LeetCode 436_Find Right Interval_寻找右区间](https://leetcode.com/problems/find-right-interval/)
- [ ] [LeetCode 540_Single Element in a Sorted Array_有序数组中的单一元素](https://leetcode.com/problems/single-element-in-a-sorted-array/)（二分 + 异或x^1判断奇偶性）
- [ ] [LeetCode 911_Online Election_在线选举](https://leetcode.com/problems/online-election/)（预处理+索引二分+设计题比较难读懂）
- [ ] [LeetCode 981_Time Based Key-Value Store_基于时间的键值存储](https://leetcode.com/problems/time-based-key-value-store)（设计 + 二分）
- [ ] [LeetCode 528_Random Pick with Weight_按权重随机选择](https://leetcode.com/problems/random-pick-with-weight/)（前缀和 + 二分 + 好题）
- [ ] [LeetCode 1337_The K Weakest Rows in a Matrix_矩阵中战斗力最弱的 K 行](https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/)（二分+优先队列）
- [ ] [LeetCode 363_H_Max Sum of Rectangle No Larger Than K_矩形区域不超过 K 的最大数值和](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)（二维前缀和+区间和+set+二分）
- [总结] **绝对值**+最大化最小值
- [ ] [LeetCode 475_M_Heaters_供暖器](https://leetcode.com/problems/heaters/)（双指针+索引二分+值域二分+绝对值）
- [ ] [LeetCode 220_Contains Duplicate III_存在重复元素Ⅲ](https://leetcode.com/problems/contains-duplicate-iii/)（multiset+滑动窗口+lower_bound+绝对值+迭代器）
- [总结] **数学**与二分
- [ ] [LeetCode 441_Arranging Coins_排列硬币](https://leetcode.com/problems/arranging-coins/)（二分+数学）
- [ ] [LeetCode 367_Valid Perfect Square_有效的完全平方数](https://leetcode.com/problems/valid-perfect-square/)（二分+数学）
- [ ] [LeetCode 374_Guess Number Higher or Lower_猜数字大小](https://leetcode.com/problems/guess-number-higher-or-lower/)
- [ ] [LeetCode 69_Sqrt(x)_x的平方根](https://leetcode.com/problems/sqrtx/)（二分+溢出）
- [ ] [LeetCode 611_Valid Triangle Number_有效三角形的个数](https://leetcode.com/problems/valid-triangle-number/)（双指针+二分）
- [ ] [LeetCode 29_Divide Two Integers_两数相除](https://leetcode.com/problems/divide-two-integers/)（快速幂思想+二分+快速乘法）
- [总结] **寻找重复数** acw14 是剑指offer里的经典值域二分的题，lc287也能用这个方法
- [ ] [AcWing 14. 不修改数组找出重复的数字](https://www.acwing.com/solution/content/693/)（值域二分）
- [ ] [LeetCode 287_Find the Duplicate Number_寻找重复数](https://leetcode.com/problems/find-the-duplicate-number/)（鸽巢原理+值域二分+龟兔赛跑Floyd's Cycle + 位运算）
- [总结] 用**子函数**当作判断关系（通常由 mid 计算得出） lc378, lc875, lc1011, lc1283, lc2064, lc410 题型类似
- [ ] [LeetCode 378_Kth Smallest Element in a Sorted Matrix_有序矩阵中第K小的元素](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)（二分）
- [ ] [LeetCode 875_Koko Eating Bananas_爱吃香蕉的珂珂](https://leetcode.com/problems/koko-eating-bananas/)（上取整）
- [ ] [LeetCode 1011_Capacity To Ship Packages Within D Days_在D天内送达包裹的能力](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
- [ ] [LeetCode 2064_Minimized Maximum of Products Distributed to Any Store_分配给商店的最多商品的最小值](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/) （上取整）
- [ ] [LeetCode 1283_Find the Smallest Divisor Given a Threshold_使结果不超过阈值的最小除数](https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/)（上取整）
- [ ] [LeetCode 1231_$_H_分享巧克力](https://leetcode-cn.com/problems/divide-chocolate/)（二分应用题）
- [x] [LeetCode 410_Split Array Largest Sum_分割数组的最大值(Hard)](https://leetcode.com/problems/split-array-largest-sum/)（二分+DP）【动态规划的做法还没写】
- [ ] [LeetCode 1482_Minimum Number of Days to Make m Bouquets_制作m束花所需的最少天数](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/)
- [ ] [LeetCode 1760_Minimum Limit of Balls in a Bag_袋子里最少数目的球](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)（上取整）
- [ ] [LeetCode 1610_Maximum Number of Visible Points_可见点的最大数目](https://leetcode.com/problems/maximum-number-of-visible-points/)（滑动窗口+二分查找）
- [x] LeetCode 1552.两球之间的磁力【暂时不会做】
- [x] LCP12.小张刷题计划

- [总结] **Kth element**
- [ ] [LeetCode 378_Kth Smallest Element in a Sorted Matrix_有序矩阵中第K小的元素](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)（二分）
- [ ] [LeetCode 668_Kth Smallest Number in Multiplication Table_乘法表中第k小的数](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/)（二分）
- [总结 ] **小数二分**，比较难想到的二分
- [ ] [LeetCode 1838_Frequency of the Most Frequent Element_最高频元素的频数](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)（前缀和+滑动窗口+二分）
- [ ] [LeetCode 2137_Pour Water Between Buckets to Make Water Levels Equal](https://leetcode-cn.com/problems/pour-water-between-buckets-to-make-water-levels-equal/)（小数二分）
- [ ] [LeetCode 786_K-th Smallest Prime Fraction_第 K 个最小的素数分数](https://leetcode.com/problems/k-th-smallest-prime-fraction/)（自定义排序+优先队列+小数二分+双指针）



### 8. 前缀和

- [总结] acw795, lc560, lc437, lc1658 都是涉及前缀和利器的
- [ ] [AcWing 795. 前缀和](https://www.acwing.com/activity/content/code/content/824786/)（一维前缀和）
- [ ] [LeetCode 303_Range Sum Query - Immutable_区域和检索-数组不可变](https://leetcode.com/problems/range-sum-query-immutable/)（一维前缀和）
- [ ] [LeetCode 2055_Plates Between Candles_蜡烛之间的盘子](https://leetcode.com/problems/plates-between-candles/description/)（一维前缀和）
- [ ] [AcWing 796. 子矩阵的和](https://www.acwing.com/activity/content/problem/content/830/)（二维前缀和）
- [总结] 一维前缀和 求一维区间和
- [ ] [LeetCode 560_Subarray Sum Equals K_和为K的子数组](https://leetcode.com/problems/subarray-sum-equals-k)（一维前缀和+区间和）
- [总结] 二维前缀和 求二维区间和
- [ ] [LeetCode 304_Range Sum Query 2D - Immutable_二维区域和检索-矩阵不可变](https://leetcode.com/problems/range-sum-query-2d-immutable/)（二维前缀和+区间和）
- [ ] [LeetCode 1074_H_Number of Submatrices That Sum to Target_元素和为目标值的子矩阵数量](https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/)（二维前缀和+区间和+哈希表）
- [ ] [LeetCode 363_H_Max Sum of Rectangle No Larger Than K_矩形区域不超过 K 的最大数值和](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)（二维前缀和+区间和+set+二分）
- [ ] 437_Path Sum III_路径总和 III
- [ ] 1658_Minimum Operations to Reduce X to Zero_将 x 减到 0 的最小操作数
- [ ] [LeetCode 930_M_Binary Subarrays With Sum_和相同的二元子数组](https://leetcode.com/problems/binary-subarrays-with-sum/)（前缀和+双指针+滑动窗口）
- [ ] [LeetCode 528_Random Pick with Weight_按权重随机选择](https://leetcode.com/problems/random-pick-with-weight/)（前缀和 + 二分）
- [ ] [LeetCode 1838_Frequency of the Most Frequent Element_最高频元素的频数](https://leetcode.com/problems/frequency-of-the-most-frequent-element/)（前缀和+滑动窗口+二分）
- [ ] [LeetCode 1749_Maximum Absolute Sum of Any Subarray_任意子数组和的绝对值的最大值](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)（前缀和+贪心）
- [ ] [LeetCode 1171_Remove Zero Sum Consecutive Nodes from Linked List_从链表中删去总和值为零的连续节点](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)（链表+前缀和+哈希表）
- [ ] [LeetCode 1310_XOR Queries of a Subarray_子数组异或查询](https://leetcode.com/problems/xor-queries-of-a-subarray)（树状数组 + 前缀异或）



### 9. 排序算法

**快速排序/快速选择**

- [总结] acw786, lc215 求第`k`个数为模板题
- [ ] [AcWing 786. 第k个数](https://www.acwing.com/activity/content/code/content/537801/)
- [ ] [LeetCode 215_Kth Largest Element in an Array_数组中的第K个最大元素](https://leetcode.com/problems/kth-largest-element-in-an-array/)（快速选择+优先队列）

**选择排序**
- [ ] [LeetCode 969_Pancake Sorting_煎饼排序](https://leetcode.com/problems/pancake-sorting/description/)（数组+选择排序）

**桶排序**

- [ ] [LeetCode 220_Contains Duplicate III_存在重复元素Ⅲ](https://leetcode.com/problems/contains-duplicate-iii/)（桶排序+multiset+滑动窗口+lower_bound+绝对值+迭代器）
- [ ] [LeetCode 1005_Maximize Sum Of Array After K Negations_K 次取反后最大化的数组和](https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/)（sort排序+桶排序+优先队列）

**计数排序**

- [ ] [LeetCode 1365_How Many Numbers Are Smaller Than the Current Number_有多少小于当前数字的数字](https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/)（哈希表+前缀和+计数排序+二分）

**自定义排序**

- [ ] [LeetCode 786_K-th Smallest Prime Fraction_第 K 个最小的素数分数](https://leetcode.com/problems/k-th-smallest-prime-fraction/)（自定义排序+优先队列+二分查找+双指针）

### 10. 优先搜索


#### 深度优先搜索 DFS
- [总结] 递归
- [ ] [LeetCode 394_Decode String_字符串解码](https://leetcode.com/problems/decode-string/)（栈+表达式求值+递归）
- [总结] DFS模板题
- [ ] [AcWing 842. 排列数字](https://www.acwing.com/activity/content/code/content/1119537/)
- [ ] [AcWing 843. n-皇后问题](https://www.acwing.com/activity/content/code/content/1120565/)

#### 回溯法



#### 广度优先搜索 BFS

- [总结] 综合 BFS+哈希
- [ ] [LeetCode 1036_Escape a Large Maze_逃离大迷宫](https://leetcode.com/problems/escape-a-large-maze/)（BFS+哈希表）

#### 连通分量Floodfill





### 11. 图论

- [总结] 边权为1的最短路问题用BFS求
- [ ] [AcWing 847. 图中点的层次](https://www.acwing.com/activity/content/code/content/2141324/)（模板）
- [ ] [LeetCode 127_H_Word Ladder_单词接龙](https://leetcode.com/problems/word-ladder/)（最短路+BFS+hashset+双向广度优先搜索）


**Dijkstra**

- [ ] [LeetCode 743_Network Delay Time_网络延迟时间](https://leetcode.com/problems/network-delay-time/)（最短路模板题，可用来练习最短路算法：Dijkstra/Bellman-ford/SPFA/Floyd）
- [ ] LeetCode 1514_Path with Maximum Probability_概率最大的路径（Dijkstra）
- [ ] LeetCode 1631_Path With Minimum Effort_最小体力消耗路径（Dijkstra）

**Bellman-ford**

- [ ] [LeetCode 787_Cheapest Flights Within K Stops_K 站中转内最便宜的航班](https://leetcode.com/problems/cheapest-flights-within-k-stops/)（带边数限制Bellman-ford/Dijkstra）
- [ ] LeetCode 200.岛屿数量（并查集+坐标变换）

**拓扑排序**

- [ ] - [ ] [AcWing 848. 有向图的拓扑序列](https://www.acwing.com/activity/content/problem/content/911/1/)（拓扑排序）
- [ ] [LeetCode 207_Course Schedule_课程表](https://leetcode.com/problems/course-schedule/)（拓扑排序）
- [ ] [LeetCode 210_Course Schedule II_课程表 II](https://leetcode.com/problems/course-schedule-ii/)（拓扑排序）
- [ ] [LeetCode 841_Keys and Rooms_钥匙和房间](https://leetcode.com/problems/keys-and-rooms/description/)（有向图+DFS+BFS）
- [ ] [LeetCode 1042_Flower Planting With No Adjacent_不邻接植花](https://leetcode.com/problems/flower-planting-with-no-adjacent/)
- [ ] LeetCode 310.最小高度树（BFS）
- [ ] LeetCode 332.重新安排行程（欧拉路径）
- [ ] LeetCode 399.除法求值（Floyd求最短路）
- [ ] LeetCode 547.朋友圈（并查集模板题）
- [ ] [LeetCode_0684_Redundant Connection_冗余连接](https://leetcode.com/problems/redundant-connection/)（并查集）

**二分图**

- [总结] 染色法判定二分图 acw860，lc785
- [ ] [AcWing 860. 染色法判定二分图](https://www.acwing.com/activity/content/code/content/1192912/)
- [ ] [LeetCode 785_Is Graph Bipartite?_判断二分图](https://leetcode.com/problems/is-graph-bipartite/)（染色法判定二分图）
- [总结] 无权图的最短路径问题
- [ ] [LeetCode 1091_Shortest Path in Binary Matrix_二进制矩阵中的最短路径](https://leetcode.com/problems/shortest-path-in-binary-matrix/)（Floodfill + BFS最短路 + 八联通）
- [ ] [LeetCode 752_Open the Lock_打开转盘锁](https://leetcode.com/problems/open-the-lock/)（BFS最短路）
- [ ] LeetCode 797.所有可能的路径（建图+DFS）
- [ ] LeetCode 1584.连接所有点的最小费用（最小生成树）
- [ ] LeetCode 1615.最大网络秩
- [ ] LeetCode 1627.带阈值的图连通性（并查集+数论）
- [ ] LeetCode 1631.最小体力消耗路径（并查集+坐标变换/DFS+二分）
- [ ] LeetCode 1697.检查边长度的路径是否存在（离线算法+并查集）

### 12. 动态规划

#### A) 基本一维/二维类型题

- [ ] [LeetCode 1034_Coloring A Border_边界着色](https://leetcode.com/problems/coloring-a-border/)（Floodfill DFS+BFS）(st数组三个状态)

#### B) 分割问题



#### C) 子序列问题



#### D) 背包问题



#### E) 字符串编辑



#### F) 股票交易



### 13. 分治与递归

### 14. 贪心算法

普通问题
- [ ] [LeetCode_1221_E_Split a String in Balanced Strings_分割平衡字符串](https://leetcode.com/problems/split-a-string-in-balanced-strings)（贪心）
- [ ] [LeetCode 11_M_Container With Most Water_盛最多水的容器](https://leetcode.com/problems/container-with-most-water/)（双指针+贪心）
- [ ] [LeetCode 881_M_Boats to Save People_救生艇](https://leetcode.com/problems/boats-to-save-people/)（双指针+贪心）
- [ ] 


#### A) 分配问题


- [ ] [LeetCode 455_E_Assign Cookies_分发饼干](https://leetcode.com/problems/assign-cookies/)（贪心）
- [ ] [LeetCode 135_H_Candy_分发糖果](https://leetcode.com/problems/candy/)（贪心+记忆化搜索）
- [ ] [LeetCode 55_M_Jump Game_跳跃游戏](https://leetcode.com/problems/jump-game/)（贪心）
- [ ] [LeetCode 45_H_Jump Game II 跳跃游戏 II](https://leetcode.com/problems/jump-game-ii/)（双指针+贪心+单调性）
- [ ] LeetCode 124.加油站
- [ ] LeetCode 316.去除重复字母（贪心+单调栈+哈希表）
- [ ] LeetCode 330.按要求补齐数组
- [ ] LeetCode 376.摆动序列
- [ ] LeetCode 402.移掉K位数字（贪心+单调栈）
- [ ] LeetCode 502.IPO（贪心+堆）
- [ ] LeetCode 605.种花问题
- [ ] LeetCode 649.Dota2参议院（贪心+队列）
- [ ] LeetCode 659.分割数组为连续子序列（贪心+哈希表）
- [ ] LeetCode 681.翻转矩阵后的得分（基于操作顺序的贪心）
- [总结] lc767 和 lc621 相似题，都是贪心里涉及空位的问题
- [ ] [LeetCode 767_Reorganize String_重构字符串](https://leetcode.com/problems/reorganize-string/)（贪心+优先队列+堆）
- [ ] [LeetCode 621_Task Scheduler_任务行程表](https://leetcode.com/problems/task-scheduler/)（贪心+优先队列+堆）
- [ ] LeetCode 738.单调递增是数字
- [ ] LeetCode 860.柠檬水找零
- [ ] LeetCode 1642.可以到达的最远建筑（贪心+堆）
- [ ] LeetCode 1648.销售价值减少的颜色球（贪心+优化计算）
- [ ] LeetCode 1673.找出最具竞争力的子序列（贪心+单调栈，同402）
- [ ] [LeetCode 1749_Maximum Absolute Sum of Any Subarray_任意子数组和的绝对值的最大值](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)（前缀和+贪心）
- [ ] [LeetCode 1839_Longest Substring Of All Vowels in Order_所有元音按顺序排布的最长子字符串](https://leetcode.com/problems/longest-substring-of-all-vowels-in-order)（双指针 + 贪心）


#### B) 区间类贪心

- Sort by starting points => the minimum number of intervals to cover the whole range

- [ ] [LeetCode 56_Merge Intervals_合并区间](https://leetcode.com/problems/merge-intervals/)（区间问题）

- Sort by ending points => the maximum number of intervals that are non-overlapping

- [ ] [LeetCode 435_M_Non-overlapping Intervals_无重叠区间](https://leetcode.com/problems/non-overlapping-intervals/)（区间问题）

- [ ] [LeetCode 452_M_Minimum Number of Arrows to Burst Balloons_用最少数量的箭引爆气球](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)（区间问题）

- [ ] [AcWing 905. 区间选点](https://www.acwing.com/activity/content/code/content/1660464/)

  -----

- [ ] [LeetCode 763_M_Partition Labels_划分字母区间](https://leetcode.com/problems/partition-labels/)（哈希 + 双指针 + 贪心）

- [ ] [LeetCode 122_M_Best Time to Buy and Sell Stock II_买卖股票的最佳时机 II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)（贪心）

- [ ] [LeetCode 406_M_Queue Reconstruction by Height_根据身高重建队列](https://leetcode.com/problems/queue-reconstruction-by-height/)（贪心）

- [ ] [LeetCode 665_M_Non-decreasing Array_非递减数列](https://leetcode.com/problems/non-decreasing-array/)（贪心）

- [ ] LeetCode 1024.视频拼接

#### C) 贪心 + 动态规划

- [ ] [LeetCode 45_Jump Game II_跳跃游戏 II](https://leetcode.com/problems/jump-game-ii/) (DP+Greedy)



## 【三、数学】

### 15. 中学数学

- [ ] [LeetCode 441_Arranging Coins_排列硬币](https://leetcode.com/problems/arranging-coins/)（二分+数学）
- [ ] [LeetCode 367_Valid Perfect Square_有效的完全平方数](https://leetcode.com/problems/valid-perfect-square/)（二分+数学）
- [ ] 

### 16. 试除法筛素数

**质数的判定**

- 试除法判定质数
- [ ] [AcWing 866. 试除法判定质数](https://www.acwing.com/activity/content/code/content/1594964/)

**分解质因数**

- 试除法分解质因数
- [ ] [AcWing 449. 质因数分解](https://www.acwing.com/activity/content/code/content/1884236/)
- [ ] [AcWing 867. 分解质因数](https://www.acwing.com/activity/content/code/content/1598776/)
- 试除法求约数
- [ ] [AcWing 869. 试除法求约数](https://www.acwing.com/activity/content/code/content/1596545/)
- [ ] [AcWing 3783. 第k个除数](https://www.acwing.com/activity/content/code/content/1598404/)
- 试除法求约数个数 + 约数之和
- [ ] [AcWing 870. 约数个数](https://www.acwing.com/activity/content/code/content/1653865/)
- [ ] [AcWing 871. 约数之和](https://www.acwing.com/activity/content/code/content/1655029/)
- 欧几里得算法 / 辗转相除法
- [ ] [AcWing 872. 最大公约数](https://www.acwing.com/activity/content/code/content/760076/)

 **筛素数**

- 埃氏筛法
- 欧拉筛法
- [ ] [AcWing 868. 筛质数](https://www.acwing.com/activity/content/code/content/1643811/)
- [ ] [LeetCode 204_E_Count Primes_计数质数](https://leetcode.com/problems/count-primes/)
- [ ] [AcWing 3792. 质数问题](https://www.acwing.com/activity/content/code/content/1655605/)

**秦九韶算法**

- LeetCode 7 和 AcW 445 题目一样

- [ ] [LeetCode 7_Reverse Integer_整数反转](https://leetcode.com/problems/reverse-integer/) （高精度+数学+秦九韶算法）
- [ ] [AcWing 445. 数字反转](https://www.acwing.com/activity/content/code/content/1884278/)（高精度+数学+秦九韶算法+字符串模拟）





### 18. 位运算
- [ ] [LeetCode 67_Add Binary_二进制求和](https://leetcode.com/problems/add-binary/)（高精度加法）
- [总结] acw801 和lc191都是lowbit模板题
- [ ] [AcWing 801. 二进制中1的个数](https://www.acwing.com/activity/content/problem/content/835/1/)
- [ ] [LeetCode 191_Number of 1 Bits_位1的个数](https://leetcode.com/problems/number-of-1-bits/)（lowbit）
- [ ] [LeetCode 338_Counting Bits_比特位计数](https://leetcode.com/problems/counting-bits/)（位运算+DP）
- [ ] [LeetCode 231_Power of Two_2 的幂](https://leetcode.com/problems/power-of-two/)（位运算+lowbit）
- [ ] [LeetCode 326_Power of Three_3 的幂](https://leetcode.com/problems/power-of-four/)（数论）
- [ ] [LeetCode 342_Power of Four_4 的幂](https://leetcode.com/problems/power-of-four/)（数论+位运算）
- [总结] 异或XOR
- [ ] [LeetCode 461_Hamming Distance_汉明距离](https://leetcode.com/problems/hamming-distance/)（异或）
- [ ] [LeetCode 136_Single Number_只出现一次的数字](https://leetcode.com/problems/single-number/)（异或性质）
- [ ] [LeetCode 268_Missing Number_丢失的数字](https://leetcode.com/problems/missing-number/)（异或性质+高斯定理）
- [ ] [LeetCode 540_Single Element in a Sorted Array_有序数组中的单一元素](https://leetcode.com/problems/single-element-in-a-sorted-array/)（二分 + 异或x^1判断奇偶性）
- [ ] [LeetCode 137_Single Number II_只出现一次的数字Ⅱ](https://leetcode.com/problems/single-number-ii/)（DFA 确定有限状态自动机）
- [总结] 记得好像lc287, lc36, lc260在位操作方法上有相通之处，需要复习
- [ ] [LeetCode 287_Find the Duplicate Number_寻找重复数](https://leetcode.com/problems/find-the-duplicate-number/)（鸽巢原理+值域二分+龟兔赛跑Floyd's Cycle + 位操作）
- [总结] 分组异或：lc645, lc260
- [ ] [LeetCode 645_E_Set Mismatch_错误的集合](https://leetcode.com/problems/set-mismatch)（分组异或+哈希表）
- [ ] [LeetCode 260_Single Number III_只出现一次的数字Ⅲ](https://leetcode.com/problems/single-number-iii/)（分组异或）
- [ ] [LeetCode_89_Gray Code_格雷编码](https://leetcode.com/problems/gray-code/)（格雷码+异或性质）
- [ ] LeetCode 289.生命游戏（二进制位存状态）
- [ ] [LeetCode 36_Valid Sudoku_有效的数独](https://leetcode.com/problems/valid-sudoku/)（数组模拟+二进制位存状态）
- [ ] [LeetCode 318_Maximum Product of Word Lengths_最大单词长度乘积](https://leetcode.com/problems/maximum-product-of-word-lengths/)（映射 + 二进制位存状态）
- [ ] [LeetCode 187_Repeated DNA Sequences_重复的DNA序列](https://leetcode.com/problems/repeated-dna-sequences/)（哈希表+字符串哈希+滑动窗口+二进制位存状态）
- [ ] [LeetCode 216_Combination Sum III_组合总和 III](https://leetcode.com/problems/combination-sum-iii/)（回溯 + 二进制位存状态）
- [ ] [LeetCode 371_Sum of Two Integers_两整数之和](https://leetcode.com/problems/sum-of-two-integers/)（异或算不带进位的和）
- [ ] LeetCode 389.找不同（异或性质）
- [ ] LeetCode 405.数字转换为十六进制数（进制转换）
- [ ] LeetCode 476.数字的补数
- [ ] LeetCode 477.汉明距离总和
- [ ] LeetCode 1680.连接连续二进制数字（位运算）
- [总结] acw89是快速幂，lc29运用了快速幂思想
- [ ] [AcWing 89. a^b](https://www.acwing.com/activity/content/code/content/786650/)（快速幂）
- [ ] [LeetCode 29_Divide Two Integers_两数相除](https://leetcode.com/problems/divide-two-integers/)（快速幂思想+二分+快速乘法）
- [ ] [LeetCode 372_Super Pow_超级次方](https://leetcode.com/problems/super-pow/)（秦九韶+快速幂+递归）








### 19. 数字处理



### 20. 随机与取样



## ----------------





## 3. 链表

- [ ] [LeetCode 2_Add Two Numbers_两数相加](https://leetcode.com/problems/add-two-numbers/)（高精度加法）
- [ ] LeetCode 445.两数相加Ⅱ（高精度加法+栈）
- [ ] LeetCode 19.删除链表的倒数第N个节点
- [ ] LeetCode 21.合并两个有序链表
- [ ] LeetCode 23.合并K个升序链表（多路归并）
- [ ] LeetCode 24.两两交换链表中的节点
- [ ] LeetCode 25.K个一组翻转链表
- [ ] LeetCode 61.旋转链表（快慢指针）
- [ ] LeetCode 83.删除排序链表中的重复元素
- [ ] LeetCode 82.删除排序链表中的重复元素Ⅱ
- [ ] LeetCode 86.分隔链表
- [ ] LeetCode 206.翻转链表
- [ ] LeetCode 92.反转链表Ⅱ
- [ ] LeetCode 143.重排链表
- [ ] LeetCode 160.相交链表
- [ ] LeetCode 203.移除链表元素
- [ ] LeetCode 234.回文链表
- [ ] LeetCode 237.删除链表中的节点
- [ ] LeetCode 328.奇偶链表
- [ ] LeetCode 707.设计链表（设计单链表，双链表模板题）
- [ ] LeetCode 876.链表的中间节点









## 5. 树

- [ ] LeetCode 98.验证二叉搜索树
- [ ] LeetCode 99.恢复二叉搜索树（Morris遍历）
- [ ] LeetCode 100.相同的树
- [ ] LeetCode 101.对称二叉树
- [ ] LeetCode 102.二叉树的层序遍历
- [ ] LeetCode 107.二叉树的层次遍历Ⅱ
- [ ] LeetCode 103.二叉树的锯齿形层次遍历
- [ ] LeetCode 104.二叉树的最大深度
- [ ] LeetCode 105.从前序和中序遍历序列构造二叉树
- [ ] LeetCode 106.从中序和后序遍历序列构造二叉树
- [ ] LeetCode 108.将有序数组转换为二叉搜索树
- [ ] LeetCode 109.有序链表转换二叉搜索树
- [ ] LeetCode 110.平衡二叉树
- [ ] LeetCode 111.二叉树的最小深度
- [ ] LeetCode 112.路径总和
- [ ] LeetCode 113.路径总和Ⅱ
- [ ] LeetCode 114.二叉树展开为链表
- [ ] LeetCode 116.填充每个节点的下一个右侧节点指针
- [ ] LeetCode 117.填充每个节点的下一个右侧节点指针Ⅱ
- [ ] LeetCode 124.二叉树中的最大路径和
- [ ] LeetCode 129.求根到叶子节点数字之和
- [ ] LeetCode 144.二叉树的前序遍历
- [ ] LeetCode 145.二叉树的后序遍历
- [ ] LeetCode 173.二叉搜索树迭代器
- [ ] LeetCode 222.完全二叉树的节点个数
- [ ] LeetCode 226.翻转二叉树
- [ ] LeetCode 230.二叉搜索树中第K小的元素
- [ ] LeetCode 297.二叉树的序列化与反序列化
- [ ] LeetCode 352.将数据流变为多个不相交区间（平衡二叉树TreeSet）
- [ ] LeetCode 404.左叶子之和
- [ ] LeetCode 429.N叉树的层序遍历
- [ ] LeetCode 449.序列化和反序列化二叉搜索树
- [ ] LeetCode 450.删除二叉搜索树中的节点
- [ ] LeetCode 501.二叉搜索树中的众数
- [ ] LeetCode 513.找树左下角的值（BFS）
- [ ] LeetCode 515.在每个树行中找最大值（BFS）
- [ ] LeetCode 1609.奇偶树（BFS）
- [总结] lc988 为二叉树找路径问题
- [ ] [LeetCode  988_Smallest String Starting From Leaf_从叶结点开始的最小字符串](https://leetcode.com/problems/smallest-string-starting-from-leaf/)

### 5.2 二叉搜索树

- [ ] [LeetCode 669_Trim a Binary Search Tree_修剪二叉搜索树](https://leetcode.com/problems/trim-a-binary-search-tree/)（递归+内存回收）

### 5.3 树的 DFS 和 BFS

- [ ] [LeetCode 623. Add One Row to Tree_在二叉树中增加一行](https://leetcode.com/problems/add-one-row-to-tree/)（BFS+DFS）

### 5.4 综合性DFS题

- [ ] [LeetCode 1600_Throne Inheritance_皇位继承顺序](https://leetcode.com/problems/throne-inheritance/)（DFS + 哈希 + 树 + 设计）







### 7.4 逆波兰表达式/计算器表达式求值

- [ ] [LeetCode 150_Evaluate Reverse Polish Notation_逆波兰表达式求值](https://leetcode.com/problems/evaluate-reverse-polish-notation/)
- [ ] [AcWing 151. 表达式计算4](https://www.acwing.com/activity/content/code/content/917204/)
- [ ] [LeetCode 227_Basic Calculator II_基本计算器 II(Medium)](https://leetcode.com/problems/basic-calculator-ii/)
- [ ] [LeetCode 224_Basic Calculator_基本计算器(Hard)](https://leetcode.com/problems/basic-calculator/)
- [ ] 

### 7.5 括号序列

- [ ] LeetCode 20.有效的括号
- [ ] LeetCode 32.最长有效括号

## 11.排序

- [ ] LeetCode 147.对链表进行插入排序
- [ ] LeetCode 148.排序链表（链表归并排序）
- [ ] LeetCode 264.丑数Ⅱ（多路归并）
- [ ] LeetCode 313.超级丑数（多路归并）
- [ ] LeetCode 912.排序数组（排序模板题）
- [ ] LeetCode 1122.数组的相对排序（自定义排序/计数排序）
- [ ] LeetCode 1464.数组中两元素的最大乘积
- [ ] LeetCode 1465.切割后面积最大的蛋糕
- [ ] LeetCode 1636.按照频率将数组升序排序（自定义排序）
- [ ] LeetCode 1637.两点之间不包含任何点的垂直最宽面积

## 12.数学

- [ ] LeetCode 43.字符串相乘（高精度乘法）
- [ ] LeetCode 50.pow(x,n)（快速幂）
- [ ] LeetCode 60.排列序列（字典序找位置）
- [ ] LeetCode 67.二进制求和（二进制的高精度加法）
- [ ] LeetCode 149.直线上最多的点数（平面几何、斜率）
- [ ] LeetCode 166.分数到小数（模拟除法找循环节）
- [ ] LeetCode 172.阶乘后的零
- [ ] LeetCode 179.最大数（自定义排序）
- [ ] LeetCode 202.快乐数（快慢指针）
- [ ] LeetCode 233.数字1的个数（计数问题）
- [ ] LeetCode 263.丑数（质因数分解）
- [ ] LeetCode 204.计数质数（筛质数）
- [ ] LeetCode 205.同构字符串（双射）
- [ ] LeetCode 223.矩形面积（求面积）
- [ ] LeetCode 258.各位相加
- [ ] LeetCode 270.单词规律（双射）
- [ ] LeetCode 292.Nim游戏（博弈论）
- [ ] LeetCode 319.灯泡开关（算数基本定理、约数）
- [ ] LeetCode 343.整数拆分（因数分解）
- [ ] LeetCode 357.计算各个位数不同的数字个数（计数问题）
- [ ] LeetCode 365.水壶问题（裴蜀定理）
- [ ] LeetCode 397.整数替换（模拟）
- [ ] LeetCode 412.Fizz Buzz（因数）
- [ ] LeetCode 415.字符串相加（高精度加法）
- [ ] LeetCode 423.从英文中重建数字（计数问题）
- [ ] LeetCode 440.字典序的第K小数字（计数问题，模拟遍历十叉树）
- [ ] 
- [ ] LeetCode 459.重复的子字符串（循环节）
- [ ] LeetCode 462.最少移动次数使数组元素相等Ⅱ（中位数）
- [ ] LeetCode 463.岛屿的周长（求平面图形周长）
- [ ] LeetCode 492.构造矩形
- [ ] LeetCode 1492.n的第k个因子（因数）
- [ ] LeetCode 1551.使数组中所有元素相等的最小操作数
- [ ] LeetCode 1643.第K条最小指令（字典序+组合数+计数问题）
- [ ] [LeetCode_914_X of a Kind in a Deck of Cards_卡牌分组](https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/)（欧几里得算法）
- [ ] [Project Euler 5_Smallest multiple](https://projecteuler.net/problem=5)（欧几里得算法）
- [ ] [LeetCode 1131_Maximum of Absolute Value Expression_绝对值表达式的最大值](https://leetcode.com/problems/maximum-of-absolute-value-expression/)（消绝对值）
- [ ] [AcWing 727. 菱形](https://www.acwing.com/file_system/file/content/whole/index/content/1883303/)（曼哈顿距离）

其他：
- [ ] 费马平方和定理：[LeetCode 633. 平方数之和](https://leetcode.com/problems/sum-of-square-numbers/)

## 13.搜索

### 13.1 DFS



- [ ] LeetCode 17.电话号码的字母组合
- [ ] LeetCode 22.括号生成
- [ ] LeetCode 37.解数独
- [ ] LeetCode 52.N皇后Ⅱ
- [ ] LeetCode 51.N皇后
- [ ] [LeetCode 46_Permutations_全排列](https://leetcode.com/problems/permutations/)（DFS + 回溯）
- [ ] [LeetCode 47_Permutations II_全排列 II](https://leetcode.com/problems/permutations-ii/)（DFS + 回溯 + 判重）
- [ ] [LeetCode 77_Combinations_组合](https://leetcode.com/problems/combinations/)（DFS + 回溯）
- [ ] [LeetCode 39_Combination Sum_组合总和](https://leetcode.com/problems/combination-sum/)（DFS + 回溯）
- [ ] [LeetCode 40_Combination Sum II_组合总和 II](https://leetcode.com/problems/combination-sum-ii/)（DFS + 回溯 + 判重）
- [ ] [LeetCode 216_Combination Sum III_组合总和 III](https://leetcode.com/problems/combination-sum-iii/)（DFS + 回溯 + 二进制位存状态）
- [ ] LeetCode 78.子集
- [ ] LeetCode 90.子集Ⅱ
- [ ] LeetCode 79.单词搜索
- [ ] LeetCode 93.复原IP地址
- [ ] LeetCode 130.被围绕的区域（Flood Fill）
- [ ] LeetCode 133.克隆图
- [ ] LeetCode 138.复制带随机指针的链表
- [ ] LeetCode 301.删除无效的括号
- [ ] LeetCode 386.字典序排数（模拟遍历Trie树）
- [ ] LeetCode 417.太平洋大西洋水流问题（Flood Fill）
- [ ] LeetCode 430.扁平化多级双向链表（可看成二叉树的层序遍历）
- [ ] LeetCode 473.火柴拼正方形
- [ ] LeetCode 842.将数组拆分成斐波那契数列

### 13.2 BFS

- [ ] [LeetCode 994_Rotting Oranges_腐烂的橘子](https://leetcode.com/problems/rotting-oranges/)（BFS）
- [ ] [LeetCode 127_Word Ladder_单词接龙(Hard)](https://leetcode.com/problems/word-ladder/)（BFS+最短路）
- [ ] LeetCode 126.单词接龙Ⅱ（BFS+DFS）
- [ ] LeetCode 433.最小基因变化
- [ ] LeetCode 690.员工的重要性（BFS/DFS）

### 13.3 方向数组
- [ ] [LeetCode 54_Spiral Matrix_螺旋矩阵](https://leetcode.com/problems/spiral-matrix/)（方向数组）
- [ ] [LeetCode 2069. Walking Robot Simulation II_模拟行走机器人 II](https://leetcode.com/problems/walking-robot-simulation-ii/)（方向数组）



## 15.分治

- [ ] LeetCode 95.不同的二叉搜索树（卡特兰数）
- [ ] LeetCode 241.为表达式设置优先级（卡特兰数）
- [ ] LeetCode 105.从前序和中序遍历序列构造二叉树
- [ ] LeetCode 106.从中序和后序遍历序列构造二叉树
- [ ] LeetCode 108.将有序数组转换为二叉搜索树
- [ ] LeetCode 109.有序链表转换二叉搜索树



## 16. 动态规划

### 16.1 路径问题 (数字三角形/矩形)

- [总结] DP矩形路径问题 lc62, lc63, lc64 都是相同递推方法
- [ ] [LeetCode 62_Unique Paths_不同路径](https://leetcode.com/problems/unique-paths/)
- [ ] [LeetCode 63_Unique Paths II_不同路径 II](https://leetcode.com/problems/unique-paths-ii/)
- [ ] [LeetCode 64_Minimum Path Sum_最小路径和](https://leetcode.com/problems/minimum-path-sum/)
- [总结] DP三角形路径问题 lc118, lc119, lc120
- [ ] [LeetCode 118_Pascal's Triangle_杨辉三角](https://leetcode.com/problems/pascals-triangle/)（递推）
- [ ] [LeetCode 119_Pascal's Triangle II_杨辉三角Ⅱ](https://leetcode.com/problems/pascals-triangle-ii/)（滚动数组）
- [ ] [LeetCode 120_Triangle_三角形最小路径和](https://leetcode.com/problems/triangle/)
- [ ] [LeetCode 931_Minimum Falling Path Sum_下降路径最小和](https://leetcode.com/problems/minimum-falling-path-sum/)（滚动数组）
- [总结] lc1289 和 lc265 本质一样，与上一行的列不重合
- [ ] [LeetCode 1289_Minimum Falling Path Sum II_下降路径最小和  II(Hard)](https://leetcode.com/problems/minimum-falling-path-sum-ii/)
- [ ] [LeetCode 265_Paint House II_粉刷房子 II](https://leetcode.com/problems/paint-house-ii/)
- [ ] [LeetCode 1301_Number of Paths with Max Score_最大得分的路径数目$(Hard)](https://leetcode.com/problems/number-of-paths-with-max-score/)



### 16.2 Fibonacci 数列
- [总结] lc70 爬楼梯模型为 lc509,  lc746 Fibonacci数列
- [ ] [LeetCode 509_Fibonacci Number_斐波那契数](https://leetcode.com/problems/fibonacci-number/)
- [ ] [LeetCode 1137_N-th Tribonacci Number_第 N 个泰波那契数](https://leetcode.com/problems/n-th-tribonacci-number/)
- [ ] [LeetCode 70_Climbing Stairs_爬楼梯](https://leetcode.com/problems/climbing-stairs/)（递归+动态规划+Fibonacci）
- [ ] [LeetCode 746_Min Cost Climbing Stairs_使用最小花费爬楼梯](https://leetcode.com/problems/min-cost-climbing-stairs/) （递归+动态规划+Fibonacci）



### 16.3 字符串上的动态规划

- [总结] lc5, lc131, lc132 都有判断回文串的部分
- [ ] [LeetCode 5_Longest Palindromic Substring_最长回文子串](https://leetcode.com/problems/longest-palindromic-substring/)（DP+中心扩展法+ Manacher）
- [ ] [LeetCode 131_Palindrome Partitioning_分割回文串](https://leetcode.com/problems/palindrome-partitioning/)（DP+DFS）
- [总结] lc1278, lc813, lc132 套路很像，都是区间DP
- [ ] [LeetCode 132_Palindrome Partitioning II_分割回文串 II(Hard)](https://leetcode.com/problems/palindrome-partitioning-ii/)（区间DP）
- [ ] [LeetCode 1278_Palindrome Partitioning III_分割回文串 III(Hard)](https://leetcode.com/problems/palindrome-partitioning-iii/)（区间DP）
- [ ] [LeetCode 813_Largest Sum of Averages_最大平均值和的分组](https://leetcode.com/problems/largest-sum-of-averages/)（区间DP）
- [ ] [LeetCode 139_Word Break_单词拆分](https://leetcode.com/problems/word-break/)（DP+字符串哈希）
- [ ] [Leetcode 161_One Edit Distance_一个编辑距离](https://leetcode.com/problems/one-edit-distance/)（与 lc72有点像）



### 16.2 背包问题

#### 16.2.1 01背包

- [ ] LeetCode 416_Partition Equal Subset Sum_分割等和子集
- [ ] LeetCode 494_Target Sum_目标和

#### 16.2.2 完全背包

- [ ] [AcWing 1023. 买书](https://www.acwing.com/activity/content/problem/content/1271/1/)
- [ ] [LeetCode 279_Perfect Squares_完全平方数](https://leetcode.com/problems/perfect-squares/)
- [总结] lc322、acw279 和 lc518 很像，这三题可以一起总结
- [ ] [LeetCode 322_Coin Change_零钱兑换](https://leetcode.com/problems/coin-change/)
- [ ] [AcWing 279. 自然数拆分](https://www.acwing.com/activity/content/problem/content/595/1/)
- [ ] [LeetCode 518_Coin Change 2_零钱兑换 II](https://leetcode.com/problems/coin-change-2/)


#### 16.2.3 二维费用背包

- [ ] [AcWing 8. 二维费用的背包问题](https://www.acwing.com/activity/content/problem/content/1277/1/)
- [ ] [LeetCode 474_Ones and Zeroes_一和零](https://leetcode.com/problems/ones-and-zeroes/) 
- [ ] [AcWing 1022. 宠物小精灵之收服](https://www.acwing.com/problem/content/1024/) (题目略长)



### 16.3 子序列/子字符串问题

#### 16.3.1 最长上升子序列(LIS模型)

- [总结] lc300 两种方法(DP + 二分)正好对应 acw895, acw896 这两个模板

- [ ] [AcWing 895. 最长上升子序列](https://www.acwing.com/activity/content/problem/content/1003/1/)

- [ ] [AcWing 896. 最长上升子序列 II](https://www.acwing.com/activity/content/problem/content/1004/1/) (二分)

- [ ] [LeetCode 300_Longest Increasing Subsequence_最长上升子序列](https://leetcode.com/problems/longest-increasing-subsequence/)

- [ ] [LeetCode 354_Russian Doll Envelopes_俄罗斯套娃信封问题](https://leetcode.com/problems/russian-doll-envelopes/)（二维LIS）

- [ ] [LeetCode 368_Largest Divisible Subset_最大整除子集](https://leetcode.com/problems/largest-divisible-subset/)（LIS求方案）

#### 16.3.3 最长公共子序列

- [总结] acwing897为模板题，lc583, lc72算是最长公共子序列的应用

- [ ] [AcWing 897. 最长公共子序列](https://www.acwing.com/activity/content/problem/content/1005/1/)

- [ ] [LeetCode 583_Delete Operation for Two Strings_两个字符串的删除操作](https://leetcode.com/problems/delete-operation-for-two-strings/)

- [ ] [LeetCode 72_Edit Distance_编辑距离 (Hard)](https://leetcode.com/problems/edit-distance/)

- [ ] AcWing 1017. 怪盗基德的滑翔翼

- [ ] AcWing 1014. 登山

- [ ] AcWing 482. 合唱队形

- [ ] AcWing 1012. 友好城市

- [ ] AcWing 1016. 最大上升子序列和

- [ ] AcWing 1010. 拦截导弹

- [ ] AcWing 187. 导弹防御系统

- [ ] AcWing 272. 最长公共上升子序列

- [ ] LeetCode1626.无矛盾的最佳球队（二维LIS+LIS最大和）

- [ ] LeetCode1691.堆叠长方体的最大高度（贪心+三维LIS）

#### 16.3.3 线性DP

- [ ] [LeetCode 53_Maximum Subarray_最大子序和](https://leetcode.com/problems/maximum-subarray/)
- [ ] [LeetCode 1727_Largest Submatrix With Rearrangements_重新排列后的最大子矩阵](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)

- [ ] [LeetCode 115_Distinct Subsequences_不同的子序列(Hard)](https://leetcode.com/problems/distinct-subsequences/)
- [ ] [LeetCode 91_Decode Ways_解码方法](https://leetcode.com/problems/decode-ways/)
- [ ] [LeetCode 639_Decode Ways II_解码方法 II (Hard)](https://leetcode.com/problems/decode-ways-ii/)
- [ ] LeetCode96.不同的二叉搜索树（递推）
- [ ] LeetCode97.交错字符串
- [ ] 
- [ ] 
- [ ] LeetCode174.地下城游戏
- [ ] [LeetCode 221_Maximal Square_最大正方形](https://leetcode.com/problems/maximal-square/)（分类讨论）
- [ ] LeetCode376.摆动序列
- [ ] LeetCode514.自由之路
- [ ] LeetCode1155.掷骰子的n种方法（骰子问题）
- [ ] LeetCode1425.带限制的子序列和（动态规划+单调队列优化）
- [ ] LeetCode1696.跳跃游戏VI（动态规划+单调队列优化）

#### 抢劫问题

- [总结] lc740本质上是lc198，稍微变化一下而已

- [ ] [LeetCode 198_House Robber_打家劫舍](https://leetcode.com/problems/house-robber/)
- [ ] [LeetCode 740_Delete and Earn_删除与获得点数](https://leetcode.com/problems/delete-and-earn/)
- [ ] [LeetCode 213_House Robber II_打家劫舍Ⅱ](https://leetcode.com/problems/house-robber-ii/)

#### 方格取数问题(矩阵双路径)

- [ ] LeetCode741.摘樱桃
- [ ] LeetCode1463.摘樱桃Ⅱ

#### 股票问题

- [ ] LeetCode121.买卖股票的最佳时机（贪心）
- [ ] LeetCode122.买卖股票的最佳时机Ⅱ（贪心）
- [ ] LeetCode123.买卖股票的最佳时机Ⅲ（前后缀分解也能做）
- [ ] LeetCode188.买卖股票的最佳时机Ⅳ
- [ ] LeetCode309.最佳买卖股票时机含冷冻期（状态机）
- [ ] LeetCode714.买卖股票的最佳时机含手续费（状态机）

#### 表达式匹配

- [ ] LeetCode 10.正则表达式匹配
- [ ] LeetCode 44.通配符匹配

### 16.4 区间DP

- [ ] LeetCode 312.戳气球
- [ ] LeetCode 375.猜数字大小Ⅱ（极小化极大，区间DP）
- [ ] LeetCode 486.预测赢家（极小化极大，区间DP）
- [ ] LeetCode 516.最长回文子序列
- [ ] LeetCode 877.石子游戏（博弈论，区间DP，数学，486题的特例）
- [ ] LeetCode 1690.石子游戏Ⅶ（博弈论，区间DP）

### 16.5 树形DP

- [ ] LeetCode 337.打家劫舍Ⅲ

### 16.6 记忆化搜索

- [ ] [LeetCode 135_H_Candy_分发糖果](https://leetcode.com/problems/candy/)（贪心+记忆化搜索）
- [ ] LeetCode 329.矩阵中的最长递增路径
- [ ] LeetCode 464.我能赢吗(状压DP+记忆化搜索)

### 16.7 状态机DP

- [ ] LeetCode 309.最佳买卖股票时机含冷冻期（状态机）
- [ ] LeetCode 552.学生出勤记录2
- [ ] LeetCode 714.买卖股票的最佳时机含手续费（状态机）

### 16.8 状压DP

- [ ] LeetCode 464.我能赢吗(状压DP+记忆化搜索)
- [ ] LeetCode 1681.最小不兼容性（枚举子集）

### 16.9 最短路动态规划

[LeetCode 1824_Minimum Sideway Jumps_最少侧跳次数](https://leetcode.com/problems/minimum-sideway-jumps/)（动态规划+递推+最短路）




## 18.树状数组

一般用树状数组能解决的问题，都可以用归并排序变形来解决
- [ ] LeetCode 307.区域和检索-数组可修改（树状数组模板题）
- [ ] LeetCode 315.计算右侧小于当前元素的个数
- [ ] LeetCode 327.区间和的个数
- [ ] LeetCode 493.翻转对
- [ ] LeetCode 1649.通过指令创建有序数组
剑指offer.51.数组中的逆序对
- [ ] LeetCode 354. 俄罗斯套娃信封问题

## 19.蓄水池抽样

- [ ] LeetCode 382.链表随机节点
- [ ] LeetCode 398.随机数索引



## 20. 综合题

- [ ] [LeetCode 1631_Path With Minimum Effort_最小体力消耗路径](https://leetcode.com/problems/path-with-minimum-effort/)（二分+BFS+并查集+最短路Dijkstra）





