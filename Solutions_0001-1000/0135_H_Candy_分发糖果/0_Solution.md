# 135_H_Candy_分发糖果



## 解法一：Greedy 两遍遍历

做完了题目 455，你会不会认为存在比较关系的贪心策略一定需要排序或是选择？虽然这一 道题也是运用贪心策略，但我们只需要简单的两次遍历即可：把所有孩子的糖果数初始化为 1；先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的糖果数加 1；再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。通过这两次遍历，分配的糖果就可以满足题目要求了。这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一侧的大小关系。

在样例中，我们初始化糖果分配为 [1,1,1]，第一次遍历更新后的结果为 [1,1,2]，第二次遍历
更新后的结果为 [2,1,2]。  



## 解法二：记忆化搜索

与 acw 901滑雪类似。

给每个小朋友分的糖果数是 $f_{(i)}$，求至少发出多少糖果。

我们希望 $\Sigma f_{(i)}$ 最小，答案为每个小朋友最少能得到的糖果之和。

那么每个小朋友最少分到多少糖呢？假设求出 $dp(i)$ 表示从第 $i$ 个格子开始最多走几步，我们发现每个 $f_{(i)}$ 大于等于  $dp(i)$


## 样例
样例1：ratings = [1,0,2]
我们初始化糖果分配为 [1,1,1]，
第一次遍历更新后的结果为 [1,1,2]，
第二次遍历更新后的结果为 [2,1,2]。

样例2：ratings = [1,3,4,5,2]
Expected: 11
我们初始化糖果分配为 [1,1,1,1,1]，
第一次遍历更新后的结果为 [1,2,3,4,1]，
第二次遍历时要比较 max(4, 1+1)
第二次遍历更新后的结果为 [1,2,3,4,1]，所以答案为 11
