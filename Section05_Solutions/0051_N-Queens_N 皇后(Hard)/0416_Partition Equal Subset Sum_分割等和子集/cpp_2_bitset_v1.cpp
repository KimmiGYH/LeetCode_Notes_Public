#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<10001> bits;
        bits[0] = 1;
        int sum = 0;
        for (auto x : nums) {
            bits |= bits << x;
            sum += x;
        }
        if (sum % 2) return false;
        return bits[sum / 2];
    }
};