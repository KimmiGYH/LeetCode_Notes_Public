class Solution {
public:
    bool canJump(vector<int>& nums) {
        //j 表示能够跳到的最靠右的位置
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (j < i) return false;
            j = max(j, i + nums[i]);
        }
        return true;
    }
};