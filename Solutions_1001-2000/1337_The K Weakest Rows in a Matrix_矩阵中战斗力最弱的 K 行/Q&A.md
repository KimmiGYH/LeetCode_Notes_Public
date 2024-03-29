# 问题

有哪位好心人能帮忙看看 1337题的官方解答中 里头的一段话是什么意思啊？
https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/solution/fang-zhen-zhong-zhan-dou-li-zui-ruo-de-k-xing-by-l/


我搞明白了建堆的时间复杂度为啥可以为 $O(n)$ 了（根据节点所需的调整时间正比于堆的完全二叉树高度，并通过错位相减得到复杂度为 $O(n)$ ）

但是我没搞懂他前面说的啥啊？
`priority_queue q(greater<pair<int, int>>(), move(power));`
这里 `move` 右值引用了动态数组，相比于我自己写的一个个插入进堆的方式，有什么优点吗？这跟建堆 $O(n)$ 复杂度有啥关系吗？

回答：

- `move` 和堆的复杂度没有关系，是为了构造堆的时候节省内存空间
- 有差别的，如果使用 `push` 方法，依次插入 `m` 个元素的方式建堆，时间复杂度是 $O(m log{m})$;
- 如果直接进使用构造函数建堆，时间复杂度是 $O(m)$
