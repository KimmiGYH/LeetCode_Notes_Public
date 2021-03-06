# 131. Palindrome Partitioning_分割回文串 (Medium)

两种写法：

- 写法一：回溯

- 写法二：回溯加了 DP



首先我们预处理好哪些子串是回文串，这个可以用动态规划在 $O(n^2)$ 的时间内处理好，`dp[i][j]`代表 `s[i:j]` 是回文串。



![img_isPalindrome_DP](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0131_Palindrome%20Partitioning_%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2/img_isPalindrome_DP.png)



然后进行递归搜索，`u` 代表当前处理到哪个位置，我们从当前位置开始，枚举所有可能的回文子串，进行递归搜索直至处理完整个字符串。

![img_Backtracking](https://raw.githubusercontent.com/KimmiGYH/LeetCode_Notes_Public/master/Section05_Solutions/0131_Palindrome%20Partitioning_%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2/img_Backtracking.png)



##### 时间复杂度分析

首先考虑最多有多少个合法方案，我们可以考虑在相邻字符之间放板子，每种放板子的方法都对应一种划分方案，而每个字符间隔有放和不放两种选择，所以总共有 $2^(n−1)$ 个方案。另外对于每个方案，需要 $O(n)$ 的时间记录方案。所以总时间复杂度是 $O((2^n)*n)$。



## 判断是否是回文串的做法：

```c++
 
/** 判断字符串是否回文
    从定义可知，一个长为 n 的字符串 S 是回文串的充要条件是：
    对于 i ∈ [0, n-1]，都有 S[i] 与 S[n-1-i] 相等。
    也就是S的前一半和后一半是"镜像"的。
    基于此，应该都有了O(n)的枚举解法：
    */

    bool isPalindrome(const string& s) {
    // 只枚举前一半就 OK 了
    for(int i = 0, n = s.size(); i < n/2; i++) {
        if(s[i] != s[n-i-1]) {
        return false; // 只要有一个位置不相等，那就肯定不是回文咯
        }
    }
    return true; // 所有位置都符合要求，那当然是回文咯
    }

// 写法一：
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

// 写法二：
    bool isPalindrome(const string& s, int i, int j) {
        if (j < i)  return true;
        if (s[i++] == s[j--])  return isPalindrome(s, i, j);
        else  return false;
    }

// 写法三：
    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }


```

