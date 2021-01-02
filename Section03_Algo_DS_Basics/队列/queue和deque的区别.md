# C++中 `queue` 和 `deque` 的区别



## 1.先明白队尾和队首，`back` 和 `front` 的联系。

无论从哪个方向看：

**插入的地方就是队尾，所有的操作名字都与`back`有联系；**

**插入端的另一端就是队首，所有的操作名字都与`front`有联系；**

![img](https://pic4.zhimg.com/80/v2-742e9e59e564c846b67ae9ced0e4bbbf_720w.jpg)

### `queue` 的操作是：


`queue<int>q;` 创建一个 `int` 型空队列 `q`；

`q.empty();` 判断队列是否为空，为空返回 `true`；

`q.push(s);` 将变量 `s` 从队尾入队；

`q.pop();` 将队头元素弹出；

`q.front();` 只返回队头元素；

`q.back();` 只返回队尾元素；

`q.size();` 返回队列中元素个数；

`queue` 从队首弹出，先入先出；

**并且queue只能从队首删除元素，但是两端都能访问。**



### `deque` 的操作是：

`deque` 双端队列的操作（可以在队头队尾进行入队出队操作）

`deque<int> dq;` 创建一个数双端队列 `dq`;

`dq.empty();` 判断队列是否为空，为空返回 `true`；

`dq.push_front(s);` 将 `s` 从队头入队；

`dq.push_back(s);` 将 `s` 从队尾入队，和普通队列方式一样；

`dq.front();` 只返回队头元素；

`dq.back();` 只返回队尾元素；

`dq.pop_front();` 将队头元素弹出；

`dq.pop_back();` 将队尾元素弹出；

`dq.clear();` 将队列清空；



### `queue` 和 `deque` 的区别：

- `queue`可以访问两端但是只能修改队头

- 而`deque`可以访问两端并且可以在队首和队尾删除和插入元素



- 由于 `deque` 两端都可以压入，只用个 `push` 的话到底是用哪端压入呢？所以有了 `push_back()` 和 `push_front()`；同样，`pop()` 是弹出，所以有 `pop_back()` 和 `pop_front()`。

- 而取数的话，`queue` 和 `deque` 都可以从两端取，所以都是 `front()` 和 `back()`。