class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int k = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                k++;
                res = max(res, k);
            }
            else k = 0;
        }
        return res;
    }
};

// Runtime: 44 ms, faster than 21.76%