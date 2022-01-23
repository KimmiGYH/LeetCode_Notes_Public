class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            for (int& x : nums) {
                if (nums[i] > x)
                    res[i] ++;
            }
        }
        return res;
    }
};