# 649. Dota2 Senate_Dota2 参议院 (Medium)



**队列 + 贪心Greedy** $O(n)$

- 用两个队列 `queue`，把各自阵营的位置存入不同的队列里面；
- 然后进行循环，每次从两个队列各取一个位置出来，看其大小关系，小的那个说明在前面，就可以把后面的那个**Ban**掉，所以我们要把小的那个位置要**加回队列**里面，但是不能直接加原位置，因为下一轮才能再轮到他来Ban，所以我们要加上一个 `n`，再排入队列。
- 这样当某个队列为空时，退出循环，我们返回不为空的那个阵营。



![solve](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0649_Dota2%20Senate_Dota2%20%E5%8F%82%E8%AE%AE%E9%99%A2/solve.png)