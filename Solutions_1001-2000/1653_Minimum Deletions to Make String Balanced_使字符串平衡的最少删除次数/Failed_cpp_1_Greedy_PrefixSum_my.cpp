#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        // sa, sb 为两个前缀和；
        // sa[i] 表示某个前缀里(前i个里) a 的数量, sb[i] 表示 b 的数量
        vector<int> sa(n), sb(n);
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')  a++;
            else b++;
            sa[i] = a;
            sb[i] = b;
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++)
            res = min(res, sb[i] + (sa[n-1] - sa[i]));
        return res;
    }
};