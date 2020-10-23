# 349. Intersection of Two Arrays_两个数组的交集



## 解法一：用 `set` 和 iterator遍历

定义第一个set `record`，将`nums1`中的元素放进这个set中；

定义第二个set `resultSet`，判断`nums2`中的元素是否在第一个数组中，将在的元素的放进 `resultSet`中；

使用`iterator`遍历 `resultSet`，将元素放进 `resultVector`中。



## 解法二：用 `unordered_set`

首先将第一个数组存到哈希表里，再去枚举第二数组中的每个元素，枚举的时候对于当前元素，判断其在哈希表中是否出现过，如果出现过，就说明该元素是两个数组的共同元素，将该元素记录到答案中，同时将该元素从第一个哈希表中删掉。

第一个哈希表是 `unordered_set`，是用来判断重复的。



## 如何判断第二个数组中的元素是否在第一个数组中出现过？

使用 `find()`函数：

```c++
if (record.find(nums2[i]) != record.end())
```



使用 `count()`函数：

```c++
if (S.count(x)) { // 如果x在第一个数组中出现过的话
// 或者写成：
if (record.count(nums2[i])) {...
```

