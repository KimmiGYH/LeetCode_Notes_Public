// 1. Two Sum
// Time Complexity: O(n^2)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    int i, j;
    vector<int> twoSum(vector<int>& nums, int target) {
        for (i = 0; i != nums.size(); ++i) {
            for (j = i + 1; j != nums.size(); ++j) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {i, j};
    }
};