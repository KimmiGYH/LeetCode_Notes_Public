#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = 0;
        for (auto x : nums) n ^= x; // 出现两次的数都被消掉了,剩a^b
        int k = 0;
        while ((n >> k & 1) == 0) k++; //位第一次出现 1 时 k 的值
        cout << k << ' ';
        return {get(nums, k, 1), get(nums, k, 0)};
    }

    int get(vector<int>&nums, int k, int t) {
        int res = 0;
        for (auto x : nums)
            if ((x >> k & 1) == t) // 分成两类 第k位 为1 or 为0
                res ^= x; // 消掉出现两次的
        return res;
    }
};