class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        //   nums = [3,0,-2,-1,1,2]
        //排序nums = [-2,-1,0,1,2,3]
        //Expected: [[-2,-1,3],[-2,0,2],[-1,0,1]]
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1, k = n - 1; j < k ; j ++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                while (j < k - 1 && nums[i] + nums[j] + nums[k] > 0) k--;
                if (nums[i] + nums[j] + nums[k] == 0)
                    res.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return res;
    }
};

// 如果是 j<k 的话，跳出循环时 j 可能是等于 k 的，这样就 nums[j] 和 nums[k] 就是一个数了，就错了。