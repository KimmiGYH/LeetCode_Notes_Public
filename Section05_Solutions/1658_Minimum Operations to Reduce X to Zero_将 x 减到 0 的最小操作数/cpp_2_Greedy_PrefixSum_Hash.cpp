#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), prefix = 0;
        unordered_map<int, int> hash; // {prefix, len}
        hash[0] = 0; // prefix = 0 时, len = 0
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            hash[prefix] = i + 1;
        }
        int minlen = INT_MAX, suffix = 0;
        if (hash.find(x) != hash.end()) //为了存尽量靠两边的数而不更新数据
            minlen = hash[x];
        for (int j = n - 1; j >= 0; j--) {
            suffix += nums[j];
            int target = x - suffix;
            if (hash.find(target) != hash.end() && hash[target] < j)
                minlen = min(minlen, hash[target] + n - j);
        }
        if (minlen == INT_MAX)  return -1;
        return minlen;
    }
};