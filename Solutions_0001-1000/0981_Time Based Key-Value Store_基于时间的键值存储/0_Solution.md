# 981_Time Based Key-Value Store_基于时间的键值存储

## 解法一：设计 + 二分 $O(\log{n})$

- 为实现 `void get()` 操作，我们需要用一个哈希表存储 `void set()` 操作传入的数据。
- 具体地，哈希表的键为字符串 $key$，值为一个二元组列表，`pair<int, string>`，二元组中存储的是时间戳 $timestamp$ 和值 $value$。
  - 所以这个数据结构为：`unordered_map<string, vector<pair<int, string>> > hash;`

- 由于 `void set()` 操作中的时间戳都是严格递增的，因此二元组列表中保存的时间戳也是严格递增的，这样我们可以根据 `void get()` 操作中的 $key$ 在哈希表中找到对应的二元组列表 $pairs$，然后根据 $timestamp$ 在 $pairs$ 中二分查找。



- 题目要求：
    ```
    String get(String key, int timestamp)

    返回先前调用 set(key, value, timestamp_prev) 所存储的值，其中 timestamp_prev <= timestamp。
    ```
- 我们需要找到最大的不超过 $timestamp$ 的时间戳 `timestamp_prev`，对此，我们可以二分找到第一个超过 `timestamp_prev` 的 $timestamp$ 的二元组下标 $i$，若 $i>0$ 则说明目标二元组存在，即 $pairs[i−1]$，否则二元组不存在，返回空字符串。


**复杂度分析**

- 时间复杂度：`set()` 操作的复杂度为 $O(1)$；`get()` 操作的复杂度为 $O(\log{n})$
  - 初始化 $TimeMap$ 和 `set()` 操作均为 $O(1)$；
  - `get()` 操作为 $O(\log n)$，其中 $n$ 是 `set()` 操作的次数。
  - 最坏情况下 `set()` 操作插入的 $key$ 均相同，这种情况下 `get()` 中二分查找的次数为 $O(\log n)$。

- 空间复杂度：$O(n)$
  - 其中 $n$ 是 `set()` 操作的次数。我们需要使用哈希表保存每一次 `set()` 操作的信息。
