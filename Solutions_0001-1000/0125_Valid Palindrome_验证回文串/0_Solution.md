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

## C++中与字符判断有关的内置函数
- `isalpha(char c)` 判断字符 `c` 是否是 **字母**，如果是返回`true`，反之 `false`。
- `islower(char c)` 判断字符 `c` 是否是 **小写字母**，如果是返回 `true`，反之 `false`。
- `isupper(char c)` 判断字符 `c` 是否是 **大写字母**，如果是返回 `true`，反之 `false`。
- `isdigit(char c)` 判断字符 `c` 是否是 **数字**，如果是返回 `true`，反之 `false`。
- `isalnum(char c)` 判断字符 `c` 是否是 **字母或数字**，如果是返回 `true`，反之 `false`。
- `tolower(char c)` 将字符 `c` 转换为 **小写字母**。如果字符 `c` 无法转换为小写字母，返回字符 `c`。
- `toupper(char c)` 将字符 `c` 转换为大写字母。如果字符 `c` 无法转换为大写字母，返回字符 `c`。


























