class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size(), res = 0;
        if (n < k) return n;
        for (int i = 0, j = 0; j < n; j++) {
            hash[nums[j]]++;
            while (hash.size() > k) {
                hash[nums[i]]--;
                if (hash[nums[i]] == 0)
                    hash.erase(nums[i]);
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
