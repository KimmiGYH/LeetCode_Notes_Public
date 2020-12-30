# 692. Top K Frequent Words_前K个高频单词 (Medium)



这道题让我们求前K个高频词，跟之前那道题 [**0347_Top K Frequent Elements_前 K 个高频元素**](https://github.com/KimmiGYH/LeetCode_Notes_Public/tree/master/Section05_Solutions/0347_Top%20K%20Frequent%20Elements_%E5%89%8D%20K%20%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0) 极其类似，换了个数据类型就又是一道新题。唯一的**不同**就是之前那道题对于出现频率相同的数字，**没有顺序要求**。而这道题对于出现频率相同的单词，需要**按照字母顺序**来排。但是解法都一样，还是用**最小堆**和**桶排序**的方法。



## 解法一：最小堆 优先队列



1. 先建立每个单词和其出现次数之间的映射，然后把单词和频率的`pair`放进最小堆，如果没有相同频率的单词排序要求，我们完全可以让频率当作`pair`的第一项，这样`priority_queue`默认是以`pair`的第一项为`key`进行从大到小的排序，而当第一项相等时，又会以第二项由大到小进行排序，但这样第一项的排序方式就与题目要求的相同频率的单词要按字母顺序排列不相符。

2. 可以对`priority_queue`的排序机制进行自定义，我们让 `a.second > b.second`，让小频率的词在第一位，然后当 `a.second == b.second` 时，我们让 `a.first < b.first`，这是让字母顺序大的排在前面（特别注意：`priority_queue` 的排序机制的写法和`vector` 的 `sort` 的排序机制的写法正好顺序相反）：

   ```c++
   struct CompareString {
       bool operator()(pair<string,int>& a, pair<string,int>& b) {
           // 【minHeap】让频率小的词在前面 || 频率相同时，让字母顺序大的排在前面
           return (a.second > b.second || (a.second == b.second && a.first < b.first));
       }
   };
   ```

3. 定义好最小堆后，我们首先统计单词的出现频率，然后组成`pair`排序最小堆之中，我们只保存 `k` 个`pair`，超过了就把队首的`pair`移除队列，最后我们把单词递减循环放入结果`res`中即可。放入时也有三种写法：

   ```c++
   /* 写法一：reverse*/
   vector<string> res;
   while (!heap.empty()) {
       res.push_back(heap.top().first);
       heap.pop();            
   }
   reverse(res.begin(), res.end());
   
   
   /* 写法二：insert */
   vector<string> res;
   while (!heap.empty()) {
       auto it = res.begin();
       it = res.insert(it, heap.top().first);
       heap.pop();
   }
   
   
   /* 写法三：递减循环*/
   vector<string> res(k);
   for (int i = res.size() - 1; i >= 0; --i) {
       res[i] = heap.top().first;
       heap.pop();
   }
   return res;
   ```

   

## 解法二：堆排序的思路，利用集合`set`能自动排序的特性



1. 我们需要首先建立每个单词和其出现次数的映射，然后将其组成pair放入 `map` 中

   ```c++
   unordered_map<string, int> freq;
   for (string word : words)  ++freq[word];
   ```

2. 我们用 `map`，来建立**次数**和出现该次数所有**单词的集合 `set `**之间的映射，`map` 是从小到大排序的，这样我们从最后面取 `pair`，就是次数最大的，这里也利用了 `set` 能自动排序的特性，相同频率的单词字母排序小的在前。

   ```c++
   map<int, set<string>> m;
   for (auto a : freq) {
       m[a.second].insert(a.first); // 将freq里的string加到map的set中
   }
   ```

3. 从最后面取 `pair`，就是次数最大的。每次取出一层中所有的单词，如果此时的 `k` 大于该层的单词个数，就将整层的单词加入结果 `res` 中，否则就取前 `k` 个就行了，取完要更新 `k` 值，如果 `k` 小于等于 `0` 了，就 `break` 掉，返回结果 `res` 即可。

   ```c++
   for (auto it = m.rbegin(); it != m.rend(); ++it) {
       if (k <= 0) break;
       auto t = it->second;
       vector<string> v(t.begin(), t.end());
       if (k >= t.size()) {
   		res.insert(res.end(), v.begin(), v.end());
       } else {
       	res.insert(res.end(), v.begin(), v.begin() + k);
       }
       k -= t.size();
   }
   return res;
   ```

   

## 解法三：桶排序



示例1：单词和它的频率

```
输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2

freq = {{"i", 2}, {"love", 2}, {"coding", 1}, {"leetcode", 1}}

buckets = {{}, {"coding", "leetcode"}, {"i", "love"}, {}, {}, {}, {}}
```

|    次数    |           1            |       2       |
| :--------: | :--------------------: | :-----------: |
| 对应的单词 | {"coding", "leetcode"} | {"i", "love"} |



示例2：单词和它的频率

```
输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4

freq = {{"the", 4}, {"is", 3}, {"sunny", 2}, {"day", 1}}

buckets = {{}, {"day"}, {"sunny"}, {"is"}, {"the"}, {}, {}, {}, {}, {}, {}}
```

|    次数    |    1    |     2     |   3    |    4    |
| :--------: | :-----: | :-------: | :----: | :-----: |
| 对应的单词 | {"day"} | {"sunny"} | {"is"} | {"the"} |



1. 我们根据出现次数建立多个 `buckets`，桶的个数不会超过单词的个数，在每个桶中，我们对单词按字符顺序进行排序。
2. 我们可以用数组来表示一个桶，每一层中放一个集合，利用 `set` 的自动排序的功能，使其能按字母顺序排列。
3. 建立每个单词和其出现次数的映射，将单词存入 `buckets` 对应的下标所在的 `set` 中。
4. 由于 `buckets` 的下标从小到大，对应的次数也是从小到达排序的，这样我们倒序遍历所有的桶，这样取桶里的单词，就是次数最大的。
5. 每次取出一层中所有的单词，如果此时的 `k` 大于该层的单词个数，就将整层的单词加入结果 `res` 中，否则就取前 `k` 个就行了，取完要更新 `k` 值，如果 `k` 小于等于 `0` 了，就 `break` 掉，返回结果 `res` 即可。