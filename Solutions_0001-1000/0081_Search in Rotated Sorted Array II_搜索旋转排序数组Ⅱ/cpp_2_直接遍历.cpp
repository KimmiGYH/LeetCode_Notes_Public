#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (auto &v : nums)
            if (v == target)
                return true;
        return false;
    }
};