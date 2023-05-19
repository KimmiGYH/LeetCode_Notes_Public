class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        for (auto x : nums) {
            int k = abs(x); //存绝对值，因为x有可能已被取反
            if (nums[k-1] < 0)
                res[0] = k;
            nums[k - 1] *= -1;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            // 如果当前这个位置是正数，并且i+1不等于出现两次的数的话
            if (nums[i] > 0 && i + 1 != res[0]) {
                res[1] = i + 1; //那么是出现零次的数
            }
        }
        return res;
    }
};