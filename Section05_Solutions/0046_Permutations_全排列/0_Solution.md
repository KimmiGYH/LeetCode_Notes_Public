# 46. Permutations_全排列



##### (回溯) $O(n×n!)$

我们从前往后，一位一位枚举，每次选择一个没有被使用过的数。

选好之后，将该数的状态改成**已被使用**，同时将该数记录在相应位置上，然后递归。

递归返回时，不要忘记将该数的状态改成**未被使用**，并将该数从相应位置上删除。

![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0046_Permutations_%E5%85%A8%E6%8E%92%E5%88%97/solve.png)

