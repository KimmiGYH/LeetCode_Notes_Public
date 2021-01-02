# 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K_和为 K 的最少斐波那契数字数目 (Medium)



**(贪心Greedy)**

我们构造出所有小于等于 *k* 的斐波那契数，随后贪心地从大到小选取即可。

对于任意给定的 *k*，存在一种最优的选择方法，其中我们选择了不超过 *k* 的最大斐波那契数。