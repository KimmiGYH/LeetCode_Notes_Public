# 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K_和为 K 的最少斐波那契数字数目 (Medium)



**(贪心Greedy)**

我们构造出所有小于等于 *k* 的斐波那契数，随后贪心地从大到小选取即可。

对于任意给定的 *k*，存在一种最优的选择方法，其中我们选择了不超过 *k* 的最大斐波那契数。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/1414_Find%20the%20Minimum%20Number%20of%20Fibonacci%20Numbers%20Whose%20Sum%20Is%20K_%E5%92%8C%E4%B8%BA%20K%20%E7%9A%84%E6%9C%80%E5%B0%91%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%AD%97%E6%95%B0%E7%9B%AE/solve.png)