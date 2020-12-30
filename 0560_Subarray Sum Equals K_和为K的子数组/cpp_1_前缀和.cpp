#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash; // {{数组之和, 出现次数}}
        int sum = 0, prefixSum = 0, res = 0;
        hash[0] = 1;
        for (auto x : nums) {
            sum += x;
            prefixSum = sum - k;
            res += hash[prefixSum];
            hash[sum]++;           
        }
        return res;
    }
};