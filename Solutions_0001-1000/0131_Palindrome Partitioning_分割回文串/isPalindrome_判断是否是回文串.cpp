#include <string>
using namespace std;

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

