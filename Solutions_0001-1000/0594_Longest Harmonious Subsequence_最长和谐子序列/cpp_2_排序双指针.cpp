class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; j < nums.size(); j++) {
            while (nums[j] - nums[i] > 1) i++;
            if (nums[j] - nums[i] == 1)
                res = max(res, j - i + 1);
        }
        return res;
    }
};
