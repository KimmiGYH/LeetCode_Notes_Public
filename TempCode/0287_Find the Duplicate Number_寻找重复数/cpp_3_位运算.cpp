#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0, n = nums.size() - 1;
        for (int p = 0; p < 32; ++p) {
            int bit = (1 << p), x = 0, y = 0;
            for (int i = 0; i <= n; ++i) {
                if (nums[i] & bit) ++x;
                if (i & bit) ++y;
            }
            // if (x > y) res |= bit;
            if (x > y) res |= (1 << p);
        }
        return res;    
    }
};