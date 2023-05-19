#include <string>
using namespace std;

class Solution {
public:
    typedef unsigned long long ULL;
    const ULL P = 131;
    int strStr(string haystack, string needle) {
        if (!needle.size())  return 0;
        int n = haystack.size(), m = needle.size();
        ULL h = 0, ref_h = 0, ans = 1;
        for (int i = 0; i < m; ++ i) {
            h = h * P + (haystack[i] - 'a');
            ref_h = ref_h * P + (needle[i] - 'a');
            ans *= P;
        }
        if (ref_h == h) return 0;
        // for (int i = 1; i <= n - m; i ++) {
        //     h = h * P - (haystack[i - 1] - 'a') * ans + haystack[m + i - 1] - 'a';
        //     if (h == ref_h)  return i;
        // }
        for (int i = 0; i < n - m; i ++) {
            h = h * P - (haystack[i] - 'a') * ans + haystack[m + i] - 'a';
            if (h == ref_h)  return i + 1;
        }
        return -1;
    }
};