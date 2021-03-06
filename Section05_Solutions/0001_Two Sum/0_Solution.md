# 1. Two Sum

效率最高且最方便的做法是方法二：哈希表；方法三：头尾指针法（杨氏矩阵）的做法也不错。

这道题的最优的做法时间复杂度是 O(n)。

熟悉扫描数组，对每一个元素，在`map`中找到能组着给定值的另一半数字。
如果找到了，直接返回 2 个数字的下标即可。
如果找不到，就把这个数字存入 `map`中，等待扫到“另一半”数字的时候，再取出来返回结果。

## 方法一：暴力法，时间复杂度O(n^2) 会超时

遍历每个元素 `nums[i]`，并查找是否存在一个值使得 `nums[i] + nums[j] == target`，
即解题关键主要是想找到 `num[j] = target - num[i]`，是否也在 list 中

## 方法二：哈希表 / 字典，用一个哈希表存储每个数对应的下标，时间复杂度 O(n)

写法1：

遍历每个元素，把元素存入哈希表中 (unordered_map)中；

之后让整数 `val = target - nums[i]`，
设置条件，如果 `val` 在哈希表中，且返回的下标不重复，
那么返回下标值。

python 可以用字典，并用 `enumerate` 遍历列表同时查字典。

写法2：

开个循环，`i`作为原数组`nums` 的下标进行移动，
新建哈希表 `indices`；
让 `val = target - nums[i];`，查找 `val` 是否在`indices`中，
如果不在，那么把原来 `nums` 里的值`nums[i]`作为key，及其下标`i`作为 value，存入新建的哈希表`indices`里；
如果找得到，那么返回`val`所映射的下标以及原下标`i`。

## 方法三：头尾指针法（利用杨氏矩阵），时间的复杂度 O(n)

**杨氏矩阵**的定义：有一个二维数组。数组的每行从左到右是递增的，每列从上到下是递增的。
例如：数组
1 2 3
2 3 4
3 4 5
或者
1 2 3
4 5 6
7 8 9

`p` 和 `q`两个指针，如果数值 `a + b < target` 说明`a`和`b`值太小，所以移动指针 `p++`；
相反如果数值`a + b > target` 说明`a`和`b`值太大，所以移动指针`q--`。

## 方法四：二分查找，时间复杂度 O(nlog(n))

用二分法查找所求的下标，定好 `index1`，`index2`，分别对应原数组值`nums[i]` / `vec[i].first`(用 pair 保存的前提下) 的下标 和 `val` 的下标。

用`my_binary_search()`来求出 `index2` 的值。
定义 `head`, `tail`, `mid`，最后求出 `vec[mid].second` 即我们所要求的下标`index2`。
