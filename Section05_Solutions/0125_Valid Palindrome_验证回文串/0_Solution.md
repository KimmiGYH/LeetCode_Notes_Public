# 125. Valid Palindrome_验证回文串

## 解法一：双指针

```cpp
    bool check(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }
```

上面的代码等同于 **字符串** 的 `isalnum()` 方法。

```cpp
if (!isalnum(s[i])) i++;
if (!isalnum(s[j])) j--;
```

如果不是字母或数字而是其他符号的话，则将指针往后or往前挪。

```cpp
if (tolower(s[i]) != tolower(s[j])) return false;
else true
```

如果小写字母有出现不同，则 `return false`，如果完全相同，则`return true`。