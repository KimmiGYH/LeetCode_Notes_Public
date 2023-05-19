# 239. Sliding Window Maximum_滑动窗口最大值(Hard)



## 解法一：双端队列 deque

![solve1](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0239_Sliding%20Window%20Maximum_%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC/solve1.png)

题目中的 Follow up 要求代码的时间复杂度为 $O(n)$。提示我们要用双向队列 `deque` 来解题，并提示我们窗口中只留下有用的值，没用的全移除掉。

思路：

- 用双端队列 `deque` 保存**数字的下标**，遍历整个数组。

- 如果此时队列的首元素是 `i-k` 的话，表示队首下标对应的最大的数字此时不在窗口中了，就要移除，则移除队首元素。

- 然后比较队尾元素和将要进来的值，如果小的话就都移除，这样能保持一个单调队列，队首下标对应的数一定最大。
- 然后此时我们把队下标对应的值加入结果中即可



## 解法二：优先队列 priority queue

![solve2](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0239_Sliding%20Window%20Maximum_%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC/solve2.png)

- 使用优先队列来做，即最大堆，里面放一个 `pair`，由**数字**和其所在**下标**组成的。

- 在遍历每个数字时，进行 `while` 循环，假如优先队列中最大的数字此时不在窗口中了，就要移除（判断方法就是将队首元素的 `pair` 中的 second（位置坐标）跟 `i-k` 对比，**小于等于**就移除。）
- 然后将当前数字和其位置组成 `pair` 加入优先队列中。



## 解法三：`multiset`

![solve3](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0239_Sliding%20Window%20Maximum_%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC/solve3.png)

我们希望窗口内的数字是有序的，但是每次给新窗口排序又太费时了，所以最好能有一种类似二叉搜索树的结构，可以在 `lgn` 的时间复杂度内完成插入和删除操作，那么使用 STL 自带的 `multiset` 就能满足我们的需求，这是一种基于**红黑树**的数据结构，可以**自动对元素进行排序，又允许有重复值**，完美契合。

思路：

- 遍历每个数字，即窗口右移，若超过了k，则需要把左边界值删除
- 注意这里不能直接删除 `nums[i-k]`，因为集合中可能有重复数字，我们只想删除一个，而 `erase` 默认是将所有和目标值相同的元素都删掉，所以我们只能提供一个 `iterator`，代表一个确定的删除位置
- 先通过 `find()` 函数找到左边界 `nums[i-k]` 在集合中的位置，再删除即可
- 然后将当前数字插入到集合中
- 此时看若 `i >= k-1`，说明窗口大小正好是 `k`，就需要将最大值加入结果 `res` 中，而由于 `multiset` 是按升序排列的，最大值在最后一个元素，我们可以通过 `rbegin()` 来取出



## 解法四：DP（看不懂）



将数组分割成长度为 `k` 的小段，然后每一段的每个位置，计算其到该段左 和 该段右的最大值，之后一次遍历即可。

[米开：LeetCode 239. Sliding Window Maximum](https://youtu.be/uvsRkNiL0e0?t=588)

![solve4](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0239_Sliding%20Window%20Maximum_%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC/solve4.png)

星哥的解释：

- 大概理解就是如果`k`是数组长度这种极限情况，就只能分一块。那这一块的最大值就是**左边界右边最大值**和**右边界左边最大值**里面较大的一个；
- `k`减小以后，就能分出多个块。当滑窗就踩在每一个块的边界情况时，最大值就相当于在你们自己家找最大值。跨过两个块的时候，就相当于你们家，和隔壁老王家最大值里面更大的一个，这种情况你可以把你们家的右边界和老王家的左边界都想成无穷小；一个楼房里面，关起门来就是你们家里最大值。两家人就要从各家中选一个最大的出来比。
- 分段时候的思路就想，如果不管`k`是几，都按`1`分段，那找长度`k`划窗里最大值的时候，就相当于把`k`个分段扫一遍。如果都按`2`分段，就相当于之后把 `k/2+1` (如果不能整除的话)个分段扫一遍，这个扩张下去，只有按k分段的时候，才能只扫一个分段就能得到结果。
- 然后的思路就是，即使划窗跨过了两家人，也就是从两家人里面选最大的；
- 如果不按`k`分段，以后有可能要从好多家人取最大的，这样就是暴力的解法；
- 再往下优化就成了提前记录一下`left`和`right`，那扫1或者2个分段的时候也不要真的扫一遍了，直接就能从`left`和`right`里读了。就成了最后人家那个写法。
- 想出来这个的人很聪明。

