# LeetCode 28_Implement strStr()_实现 strStr()

## 方法一：KMP 算法

[KMP模板](https://www.acwing.com/file_system/file/content/whole/index/content/2174696/)

[【代码随想录】28. 实现 strStr()](https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC)

本篇将以如下顺序来讲解KMP，
- 什么是KMP
- KMP有什么用
- 什么是前缀表
- 为什么一定要用前缀表
- 如何计算前缀表
- 前缀表与next数组
- 使用next数组来匹配
- 时间复杂度分析
- 构造next数组
- 使用next数组来做匹配
- 前缀表统一减一 C++代码实现
- 前缀表（不减一）C++实现

## 方法二：Rabin-Karp 算法

[视频：B站：轻松掌握 Rabin-Karp](https://www.bilibili.com/video/av81581026)


《算法》P580，第32章 字符串匹配，32.1 Rabin-Karp算法

![Rabin-Karp](link)
