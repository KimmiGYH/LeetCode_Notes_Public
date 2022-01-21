class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int routeSum = 0, prefixSum = 0, res = 0;
        hash[0] = 1;
        for (auto& x : nums) {
            prefixSum += x;
            routeSum = prefixSum - k;
            res += hash[routeSum];
            hash[prefixSum]++;
        }
        return res;
    }
};