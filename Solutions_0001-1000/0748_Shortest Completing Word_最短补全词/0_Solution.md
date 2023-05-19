# 0748_Shortest Completing Word_最短补全词

### 解法一：哈希表对字符串计数模拟

- 先对 $licensePlate$ 进行词频统计（忽略空格和数字），记在 $cntlp$ 里
```cpp
for (char& c : licensePlate) {
    if (isalpha(c)) //或写成 if (c != ' ' && !isdigit(c))
        cntlp[tolower(c)] ++;
}   
```
- 再对 $words$ 进行词频统计，记在 $cntword$ 里
- 布尔函数 $check$ 判断条件，从所有符合要求的 $words[i]$ 找到最短的补全词
- 要求 $cntlp$ 里的元素全都要用上，枚举 $cntlp$，避免 $cntword$ 里的元素都不是 $cntlp$ 里的（看报错信息里的数据）

**复杂度分析**

- 时间复杂度：$O(N+L+M⋅∣Σ∣)$，其中 $N$ 是字符串 $licensePlate$ 的长度，$L$ 是 $words$ 中的所有字符串的长度之和，$M$ 是 $words$ 数组的长度，$|\Sigma|$ 为字符集合的大小，本题中有 $26$ 个英文字母，即 $|\Sigma|=26$。

空间复杂度：$O(|\Sigma|)$。

