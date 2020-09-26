#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0; i < size(nums); i++) {
            if (i % 2 == 0) 
                a = max(a + nums[i], b);
            else
                b = max(a, b + nums[i]);
        }
        return max(a, b);
    }
};
// Runtime 4 ms, Memory 8 MB 速度较慢