# 1094. Car Pooling_拼车 (Medium)



## 解法一：用 `pair` 来记录，需排序

记录上下车乘客人数的变化情况：

```cpp
vector<pair<int, int>> v; 
for (int i = 0; i < trips.size(); i++) {
    v.push_back({trips[i][1], trips[i][0]});  // {start, passengers}
    v.push_back({trips[i][2], -trips[i][0]}); // {end, -passengers}
}
```

排序里程，看对应里程的人数是否超载。



## 解法二：不排序，开数组记录

开数组 `vector<int> passengers(1001);` 记录每个里程的乘客人数变化情况，省下排序步骤。看人数是否超载。

 `O(n)`

空间复杂度： `O(1000)`



## 解法三：优先队列最小堆

- 按 start location 将 trips 排序，可用**自定义函数对象排序**。

  ```cpp
  #include <algorithm>
  #include <functional>
  #include <array>
  #include <iostream>
   
  int main()
  {
      std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
   
      // 用默认的 operator< 排序
      std::sort(s.begin(), s.end());
      for (auto a : s) {
          std::cout << a << " ";
      }   
      std::cout << '\n';
   
      // 用标准库比较函数对象排序
      std::sort(s.begin(), s.end(), std::greater<int>());
      for (auto a : s) {
          std::cout << a << " ";
      }   
      std::cout << '\n';
   
      // 用自定义函数对象排序 <========== 【看这里】
      struct {
          bool operator()(int a, int b) const
          {   
              return a < b;
          }   
      } customLess;
      std::sort(s.begin(), s.end(), customLess);
      for (auto a : s) {
          std::cout << a << " ";
      }   
      std::cout << '\n';
  }
  
  /* 输出
  0 1 2 3 4 5 6 7 8 9 
  9 8 7 6 5 4 3 2 1 0 
  0 1 2 3 4 5 6 7 8 9 
  */
  ```

  

- 使用自定义 Comparator 的 `priority_queue`

  ```c++
  struct CompareTrip {
      bool operator()(vector<int>& a, vector<int>& b) {
          return a[2] > b[2]; // minHeap
      }
  };
  
  priority_queue<vector<int>, vector<vector<int>>, CompareTrip> heap;
  ```

  

- `minHeap` 最小堆中放置较小的 end location，如果 end location < start location，那么该 trip 为 dead trip。

  这个思路和 **253. Meeting Rooms II** 的思路一致，可以听一下 253 题的分析：[Youtube: 山景城一姐](https://youtu.be/4MEkBvqE_2Q)