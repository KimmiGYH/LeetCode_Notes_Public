# C++学习之 `priority_queue` (优先队列)



### 优先队列的实现

|          | 入队     | 出队     |
| -------- | -------- | -------- |
| 普通数组 | `O(1)`   | `O(n)`   |
| 顺序数组 | `O(n)`   | `O(1)`   |
| 堆       | `O(lgn)` | `O(lgn)` |



### 使用堆实现优先队列

对于总共`N`个请求：

使用普通数组或者顺序数组，最差情况：`O(n^2)`

使用堆：`O(nlgn)`







## 升序队列 & 降序队列

```cpp
//升序队列
priority_queue <int,vector<int>,greater<int> > q;
//降序队列
priority_queue <int,vector<int>,less<int> >q;

//greater和less是std实现的两个仿函数（就是使一个类的使用看上去像一个函数。
//其实现就是类中实现一个operator()，这个类就有了类似函数的行为，就是一个仿函数类了）
```



## priority_queue的内嵌函数

```cpp
top() 访问队头元素
empty() 队列是否为空
size() 返回队列内元素个数
push() 插入元素到队尾 (并排序)
emplace() 原地构造一个元素并插入队列
pop() 弹出队头元素
swap() 交换内容
```
