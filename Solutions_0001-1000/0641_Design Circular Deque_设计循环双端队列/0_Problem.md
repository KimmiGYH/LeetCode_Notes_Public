# [641. Design Circular Deque](https://leetcode.com/problems/design-circular-deque/) (Medium)

Design your implementation of the circular double-ended queue (deque).

Implement the `MyCircularDeque` class:

- `MyCircularDeque(int k)` Initializes the deque with a maximum size of `k`.
- `boolean insertFront()` Adds an item at the front of Deque. Returns `true` if the operation is successful, or `false` otherwise.
- `boolean insertLast()` Adds an item at the rear of Deque. Returns `true` if the operation is successful, or `false` otherwise.
- `boolean deleteFront()` Deletes an item from the front of Deque. Returns `true` if the operation is successful, or `false` otherwise.
- `boolean deleteLast()` Deletes an item from the rear of Deque. Returns `true` if the operation is successful, or `false` otherwise.
- `int getFront()` Returns the front item from the Deque. Returns `-1` if the deque is empty.
- `int getRear()` Returns the last item from Deque. Returns `-1` if the deque is empty.
- `boolean isEmpty()` Returns `true` if the deque is empty, or `false` otherwise.
- `boolean isFull()` Returns `true` if the deque is full, or `false` otherwise.

 

**Example 1:**

```
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
```

 

**Constraints:**

- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `2000` calls will be made to `insertFront`, `insertLast`, `deleteFront`, `deleteLast`, `getFront`, `getRear`, `isEmpty`, `isFull`.



# [641. 设计循环双端队列](https://leetcode-cn.com/problems/design-circular-deque/)

难度中等

设计实现双端队列。
你的实现需要支持以下操作：

- `MyCircularDeque(k)`：构造函数,双端队列的大小为k。
- `insertFront()`：将一个元素添加到双端队列头部。 如果操作成功返回 true。
- `insertLast()`：将一个元素添加到双端队列尾部。如果操作成功返回 true。
- `deleteFront()`：从双端队列头部删除一个元素。 如果操作成功返回 true。
- `deleteLast()`：从双端队列尾部删除一个元素。如果操作成功返回 true。
- `getFront()`：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
- `getRear()`：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
- `isEmpty()`：检查双端队列是否为空。
- `isFull()`：检查双端队列是否满了。

**示例：**

```
MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  						// 返回 2
circularDeque.isFull();				        	// 返回 true
circularDeque.deleteLast();			        	// 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();						// 返回 4
```

**提示：**

- 所有值的范围为 [1, 1000]
- 操作次数的范围为 [1, 1000]
- 请不要使用内置的双端队列库。

