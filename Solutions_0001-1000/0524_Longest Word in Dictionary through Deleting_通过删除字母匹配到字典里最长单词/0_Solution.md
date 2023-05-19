# 524_Longest Word in Dictionary through Deleting_通过删除字母匹配到字典里最长单词

## 解法一：双指针判断子序列模板题

```cpp
int i = 0, j = 0;
while (i < n && j < m)
{
    if (a[i] == b[j]) i++;
    j++;
}

if (i == n) puts("Yes");
else puts("No");
```

- 通过模板，验证 $dictionary$ 中的每个单词 $str$ 是否是 $s$ 中的子序列
- 如果是子序列，那么更新 $res$，更新 $res$ 的情况为：
  - $res$ 为空时将满足条件的单词加进去
  - 当前单词大于结果 $res$ 的长度时，更新 $res$
  - 当前单词长度和 $res$ 相同，但是字母顺序小于结果 $res$，更新 $res$

**复杂度分析**
- 时间复杂度：$O(mn)$
  - 共 $m$ 个单词，双指针验证子序列匹配的时间复杂度为 $O(n)$，故总时间复杂度为 $O(mn)$
  - 字符串的平均长度*字符串的个数
