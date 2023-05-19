#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size(), m = needle.size();
        haystack = ' ' + haystack, needle = ' ' + needle;
        
        vector<int> next(m + 1);
        //i从2开始，因为next[1]=0
        for (int i = 2, j = 0; i <= m; i ++) {
            while (j && needle[i] != needle[j + 1])  j = next[j];
            if (needle[i] == needle[j + 1])  j ++;
            next[i] = j;
        }        
        
        for (int i = 1, j = 0; i <= n; i ++) {
            while (j && haystack[i] != needle[j + 1])  j = next[j];
            if (haystack[i] == needle[j + 1])  j ++;
            if (j == m)  return i - m;
        }
        
        return -1;
    }
};