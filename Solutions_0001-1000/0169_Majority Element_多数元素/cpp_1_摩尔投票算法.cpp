#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int r, c = 0; // r 当前有的数；c 当前数的库存
        for (auto x : nums)
            if (!c) r = x, c = 1;
            else if (r == x) c++;
            else c--;
        return r;
    }
};