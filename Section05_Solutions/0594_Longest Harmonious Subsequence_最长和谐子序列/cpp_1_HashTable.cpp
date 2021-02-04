#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto c : nums) cnt[c]++;
        int res = 0;
        for (auto [k, v] : cnt)
            if (cnt.count(k - 1))
                res = max(res, cnt[k] + cnt[k - 1]);
        return res;
    }
};