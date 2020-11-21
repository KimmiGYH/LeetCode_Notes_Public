#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        // sa, sb 为两个前缀和；sa 表示某个前缀里(前i个里) a 的数量, sb 表示 b 的数量
        vector<int> sa(n + 1), sb(n + 1);
        for (int i = 1; i <= n; i++) {
            sa[i] = sa[i-1]; // 初始化等于0
            sb[i] = sb[i-1];
            if (s[i - 1] == 'a')  sa[i]++;
            else sb[i]++;
        }

        int res = INT_MAX;
        for (int i = 0; i <= n; i++)
            res = min(res, sb[i] + (sa[n] - sa[i]));
        return res;
    }
};