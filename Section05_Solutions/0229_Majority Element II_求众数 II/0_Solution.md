# 229_Majority Element II_求众数 II

## 解法一：摩尔投票算法

- 此题为 LeetCode.169 的拓展题
- 结论：在任何数组中，出现次数大于该数组长度 $1/3$ 的值最多只有 **两个**
- 摩尔投票法其实就是**抵消法**，假设一个数的数量大于总数的 $1/3$ ，且这个数需要用两个不同的数才能抵消。则抵消到最后这个数一定还存在
- 两个变量 $r1,r2$ 作为仓库，$c1,c2$ 是仓库的计数。有两种抵消的情况
  - $r1, r2$ 有值，且 $x$ 与 $r1, r2$ 不同
  - $x$ 在某个仓库里，且新来的数与 $x$ 和另外一个仓库里的数都不相同
- 如果仓库非空且新值与仓库中的值同类，则增加计数，如果仓库为空，则新添加元素进仓库；如果仓库非空，且新值与仓库里的值不同类，则开始抵消，只需要一趟遍历即可。
