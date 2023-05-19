class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;;
        unordered_map<int, int> hash;
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++)
            s[i] = s[i-1] + nums[i-1];
        hash[0] = 1;
        for (int i = 1; i <= n; i++) {
            res += hash[s[i] - k];
            hash[s[i]] ++;
        }
        return res;
    }
};