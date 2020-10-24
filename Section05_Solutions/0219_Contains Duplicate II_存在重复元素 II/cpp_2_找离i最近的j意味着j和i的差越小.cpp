#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            // 如果x在之前出现过，且i减去x之前出现的最后一次位置hash[x]小于等于k的话
            if (hash.count(x) && i - hash[x] <= k)  return true;
            hash[x] = i;
        }
        return false;
    }
};