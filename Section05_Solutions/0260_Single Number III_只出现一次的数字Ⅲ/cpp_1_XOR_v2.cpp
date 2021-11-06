#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = 0;
        for (auto x : nums) n ^= x;
        int k = 0;
        while ((n >> k & 1) == 0) k++;
        int a = 0, b = 0;
        for (auto x : nums) {
            if ((x >> k & 1) == 0) a ^= x;
            else b ^= x;
        }
        return {a, b};
    }
};
//写在一个函数里了