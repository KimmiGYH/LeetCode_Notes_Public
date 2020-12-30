#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash; // {{数组之和, 出现次数}}
        int routeSum = 0, prefixSum = 0, res = 0;
        hash[0] = 1;
        for (auto x : nums) {
            routeSum += x;
            prefixSum = routeSum - k;
            res += hash[prefixSum];
            hash[routeSum]++;
        }
        return res;
    }
};