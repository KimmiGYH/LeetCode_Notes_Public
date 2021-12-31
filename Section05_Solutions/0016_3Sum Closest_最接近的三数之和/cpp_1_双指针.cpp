class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i >= 1 && nums[i] == nums[i-1]) continue;
            for (int j = i+1, k = n-1; j < k; ) { //这里不能写 j++ 是因为写了就表示一定会执行j++，但其实是有条件的
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(res - target))  res = sum;
                if (res == target) return target;
                else if (sum > target) k--;
                else j++;
            }
        }
        return res;
    }
};