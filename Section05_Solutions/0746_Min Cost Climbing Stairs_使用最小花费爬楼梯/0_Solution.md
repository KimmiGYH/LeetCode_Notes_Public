# 746_Min Cost Climbing Stairs_使用最小花费爬楼梯

## 解法一：动态规划 1

- 这道题应该算是之前那道 Climbing Stairs 的拓展，这里不是求步数，而是每个台阶上都有一个 $cost$，让我们求爬到顶端的最小 $cost$ 是多少。
- 换汤不换药，还是用动态规划来做。这里定义一个一维的 $dp$数组，其中 $dp[i]$ 表示爬到第 $i$ 层的最小 $cost$，然后来想 $dp[i]$ 如何推导。
- 来思考一下如何才能到第 $i$ 层呢？是不是只有两种可能性，一个是从第 $i-2$ 层上直接跳上来，一个是从第 $i-1$ 层上跳上来。不会再有别的方法，所以 $dp[i]$ 只和前两层有关系，可以写做如下：
    $$
    dp[i] = min(dp[i - 1] + cost[i - 1], dp[i- 2] + cost[i - 2])
    $$

- 最后返回最后一个数字 $dp[n]$ 即可。

## 解法二：动态规划 2

- 再来看一种 DP 的解法，跟上面的解法很相近，不同在于 $dp$ 数组长度为 $n$，其中 $dp[i]$ 表示到第 $i+1$ 层的最小 $cost$，分别初始化 $dp[0]$ 和 $dp[1]$ 为 $cost[0]$ 和 $cost[1]$。
- 然后从 $i=2$ 处开始遍历，此时更新思路是，要爬当前的台阶，肯定需要加上当前的 $cost[i]$，那么还是要从**前一层**或者**前两层**的台阶上跳上来，选择 $dp$ 值小的那个，所以递归式如下：
    $$
    dp[i] = cost[i] + min(dp[i- 1], dp[i - 2])
    $$

- 最后在最后两个 $dp$ 值中选择一个较小的返回即可。

## 解法三：动态规划空间优化

- 我们可以对空间复杂度进行优化，通过前面的分析我们可以发现，当前的 $dp$ 值仅仅依赖前面两个的值，所以不必把整个 $dp$ 数组都记录下来，只需用两个变量 $a$ 和 $b$ 来记录前两个值，然后不停的用新得到的值来覆盖它们就好了。
- 初始化 $a$ 和 $b$ 均为 $0$，然后遍历 $cost$ 数组，首先将 $a$ 和 $b$ 中较小值加上 $num$ 放入临时变量 $c$ 中，然后把 $b$ 赋给 $a$，把 $c$ 赋给$b$ 即可。

## 解法四：递归

[YouTube花花酱 LeetCode 746. Min Cost Climbing Stairs](https://youtu.be/v3WqNLmmBdk)

- 还可以用递归来写，需要优化计算量，即用 HashMap 来保存已经算过了台阶，用的还是 dp 的思想
