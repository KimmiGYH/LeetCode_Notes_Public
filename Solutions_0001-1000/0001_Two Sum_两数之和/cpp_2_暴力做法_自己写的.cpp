class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            int val = target - nums[i];
            while (nums[j] != val && j < n - 1) j ++;
            if (nums[j] == val) {
                res.push_back(i);
                res.push_back(j);
            }
        }
        return res;
    }
};