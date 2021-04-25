#include <string>
using namespace std;

class Solution {
public:
    typedef unsigned long long ULL;
    // R 进制, Q 素数, d 基数(典型取值为|∑|)
    const ULL R = 131;
    const ULL Q = 1e9 + 7;
    int strStr(string haystack, string needle) {
        if (!needle.size())  return 0;
        int n = haystack.size(), m = needle.size();
        ULL h = 0, ref_h = 0, d = 1;
        for (int i = 0; i < m; ++i) {
            h = (h * R + haystack[i] - 'a') % Q;
            ref_h = (ref_h * R + needle[i] - 'a') % Q;
            d = d * R % Q;
        }
        if (ref_h == h) return 0;
        // for (int i = 1; i <= n - m; i ++) {
        //     h = (h * R - (haystack[i - 1] - 'a') * d + haystack[m + i - 1] - 'a') % Q;
        //     if (h == ref_h && haystack.substr(i, m) == needle) return i;
        // }
        for (int i = 0; i < n - m; i ++) {
            h = (h * R - (haystack[i] - 'a') * d + haystack[m + i] - 'a') % Q;
            if (h == ref_h && haystack.substr(i + 1, m) == needle)  return i + 1;
        }
        return -1;
    }
};