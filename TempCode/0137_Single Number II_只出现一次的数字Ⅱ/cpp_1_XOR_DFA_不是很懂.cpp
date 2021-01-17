#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int two = 0, one = 0;
        for (auto x : nums) {
            one = (one ^ x) & ~two;
            two = (two ^ x) & ~one;
        }
        return one; // 返回的是 one 的个数模 3 为 1
    }
};