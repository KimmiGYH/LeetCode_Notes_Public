# 1700_5621_Number of Students Unable to Eat Lunch_无法吃午餐的学生数量 (Easy)



## 解法一：双端队列 `deque` + 哈希表 `Hash Table`

### 数据结构使用**双端队列** `deque`

定义于头文件 `<deque>`

`std::deque` （ double-ended queue ，双端队列）是有下标顺序容器，它允许在其首尾两段快速插入及删除。

deque 上常见操作的复杂度（效率）如下：

- 随机访问——常数 O(1)
- 在结尾或起始插入或移除元素——常数 O(1)
- 插入或移除元素——线性 O(n)



### 思路：

1. 开两个**双端队列** `deque`，分别存入 `vector<int> students` 和 `vector<int> sandwiches` 中的元素。
2. 用哈希表记录学生偏爱的三明治形状 `1`（方形）和 `0`（圆形）的数量。
3. 判断条件：三明治不为空，有学生爱吃队首形状的三明治
   1. 如果对不上，就把队首学生挪到队尾；
   2. 如果对上了，在哈希表中消掉某个形状的数量，另外队首的学生和三明治都去掉。
4. 最后看剩余的人数。