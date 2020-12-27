# 自定义排序 sort

(相关题 LeetCode 1094)

- 按 start location 将 trips 排序，可用**自定义函数对象排序**。

  ```cpp
  // 自定义函数对象排序

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