# 347. Top K Frequent Elements_前 K 个高频元素 (Medium)



题目大意：给定一个非空数组，返回前 `k` 个出现频率最高的元素。



## 解法一：排序

最简单的思路：扫描一遍统计频率；将频率排序，找到前 `k` 个出现频率最高的元素。

时间复杂度： `O(nlogn)`



## 解法二：优先队列

使用哈希表统计每个数字出现的个数，然后维护一个大小为`k`的小顶堆即可。

维护一个含有 `k` 个元素的优先队列。如果遍历到的元素比队列中的最小频率元素的频率高，则取出队列中最小频率的元素，将新元素入队。最终，队列中剩下的，就是前 `k ` 个出现频率最高的元素。

时间复杂度： `O(nlogk)`



## 解法三：计数排序

(哈希表，计数排序) `O(n)`

首先用哈希表统计出所有数出现的次数。

由于所有数出现的次数都在 `1` 到 `n` 之间，所以我们可以用计数排序的思想，统计出次数最多的前 `k` 个元素的下界。然后将所有出现次数大于等于下界的数输出。

##### 时间复杂度分析：

用哈希表统计每个数出现次数的计算量是 `O(n)`，计数排序的计算量是 `O(n)`，最终用下界过滤结果的计算量也是 `O(n)`，所以总时间复杂度是 `O(n)`。

![solve_3](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0347_Top%20K%20Frequent%20Elements_%E5%89%8D%20K%20%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0/solve_3.png)



## 解法四：桶排序 Bucket Sorting

[花花酱 LeetCode 347. Top K Frequent Elements](https://youtu.be/lm6pBga98-w)

(桶排序 Bucket Sorting) `O(n)`

1. 先开哈希表 `freq`，存进 `nums` 数组中元素的频率。这里可以用 `max()` 函数求出最高频率，方便后面降序循环。
2. 注意：`++freq[num]` 和 `freq[num]++` 在 `max(max_freq), 增加频率` 中是不一样的，应用 `++freq[num]`
- 前置版本：首先将运算符对象加`1`(或减`1`)，然后将改变后的对象作为求值结果。(`++`在前，先加`1`，后参与运算；)
- 后置版本：也会将运算对象加`1`(或减`1`)，但是求值结果是运算对象改变之前那个值的副本。(`++`在后，先参与运算，后加`1`。)
3. 再开哈希表 `buckets`，格式为 `unordered_map<int, vector<int>> buckets`，以便将某个频率的所有元素存入桶内。
4. 开答案数组，从最高频的开始降序循环，如果某个表示频率的 `i `在哈希表 `buckets` 中存在的话，那么就把该频率的桶内所有元素插入进答案数组。
5. 如果递减的 `i` 并不是哈希表中的频率数值，那么就 `continue` 回到 `for` 循环继续递减。



时间复杂度：`O(n)`

空间复杂度：`O(n)`

![solve_bucket](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0347_Top%20K%20Frequent%20Elements_%E5%89%8D%20K%20%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0/solve_bucket.png)