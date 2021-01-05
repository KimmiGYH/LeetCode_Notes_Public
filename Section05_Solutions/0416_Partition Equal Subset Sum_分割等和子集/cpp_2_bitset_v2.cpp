#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums)
            bits |= bits << num;
        return (sum % 2 == 0) && bits[sum >> 1];
    }
};