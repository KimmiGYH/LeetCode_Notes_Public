class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int j = i + 1;
            while (j < n && nums[j] == 1) j++;
            res = max(res, j - i);
            i = j; //这里不用回退，因为此题中 nums[j]==0 时要跳过，所以 i++ 正好
        }
        return res;
    }
};

// Runtime: 28 ms, faster than 92.60%