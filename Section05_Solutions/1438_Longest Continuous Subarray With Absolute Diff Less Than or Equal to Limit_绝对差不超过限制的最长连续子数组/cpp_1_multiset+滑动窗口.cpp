class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int n = nums.size(), res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            s.insert(nums[j]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[i]));
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};