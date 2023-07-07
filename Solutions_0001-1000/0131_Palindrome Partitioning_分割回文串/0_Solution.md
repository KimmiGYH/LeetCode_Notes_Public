# 131. Palindrome Partitioning_分割回文串 (Medium)

## 解法一：递归＋回溯

我们来分析一下切割，其实切割问题类似组合问题。

例如对于字符串abcdef：

组合问题：选取一个a之后，在bcdef中再去选取第二个，选取b之后在cdef中再选取第三个.....。
切割问题：切割一个a之后，在bcdef中再去切割第二段，切割b之后在cdef中再切割第三段.....。
感受出来了不？

所以切割问题，也可以抽象为一棵树形结构，如图：
![图解](https://code-thinking.cdn.bcebos.com/pics/131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.jpg)

- 递归函数终止条件

从树形结构的图中可以看出：切割线切到了字符串最后面，说明找到了一种切割方法，此时就是本层递归的终止条件。

**那么在代码里什么是切割线呢？**

在处理组合问题的时候，递归参数需要传入`startIndex`，表示下一轮递归遍历的起始位置，这个`startIndex`就是切割线。

```cpp
void backtracking (const string& s, int startIndex) {
    // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
    if (startIndex >= s.size()) {
        result.push_back(path);
        return;
    }
}
```

- 单层搜索的逻辑

**来看看在递归循环中如何截取子串呢？**

在 `for (int i = startIndex; i < s.size(); i++)` 循环中，我们 定义了起始位置 `startIndex`，那么 `[startIndex, i]` 就是要截取的子串。

首先判断这个子串是不是回文，如果是回文，就加入在 `vector<string> path` 中，`path` 用来记录切割过的回文子串。

```cpp
for (int i = startIndex; i < s.size(); i++) {
    if (isPalindrome(s, startIndex, i)) { // 是回文子串
        // 获取[startIndex,i]在s中的子串
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
    } else {                // 如果不是则直接跳过
        continue;
    }
    backtracking(s, i + 1); // 寻找i+1为起始位置的子串
    path.pop_back();        // 回溯过程，弹出本次已经填在的子串
}
```

注意切割过的位置，不能重复切割，所以，`backtracking(s, i + 1);` 传入下一层的起始位置为 `i + 1`。


**时间复杂度分析**

首先考虑最多有多少个合法方案，我们可以考虑在相邻字符之间放板子，每种放板子的方法都对应一种划分方案，而每个字符间隔有放和不放两种选择，所以总共有 $2^{(n−1)}$ 个方案。另外对于每个方案，需要 $O(n)$ 的时间记录方案。所以总时间复杂度是 $O(2^n*n)$。



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

## 解法二：动态规划

