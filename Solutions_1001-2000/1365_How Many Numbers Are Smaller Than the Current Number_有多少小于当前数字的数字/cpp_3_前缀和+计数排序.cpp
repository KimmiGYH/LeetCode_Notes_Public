class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> cnt(101, 0);
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            cnt[nums[i]] ++;
        for (int i = 1; i <= 100; i++)
            cnt[i] += cnt[i - 1];
        for (int& x : nums)
            res.push_back(x == 0 ? 0 : cnt[x - 1]);
        return res;
    }
};