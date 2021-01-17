#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                hash[nums[i] * nums[j]] ++;
        int res = 0;
        for (auto& [p, k] : hash)
            res += k * (k-1) / 2 * 8;
        return res;
    }
};