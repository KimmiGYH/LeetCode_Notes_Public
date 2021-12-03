// 写法一
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0, total = 0, n = nums.size(), minm = INT_MAX;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n && nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            i++, k--;
        }
            
        for (int& x : nums) {
            total += x;
            minm = min(minm, x);
        }
        res = (k % 2) ? (total - 2 * minm) : total;
        return res;
    }
};

// 写法二
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0, n = nums.size(), minm = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n && k > 0 && nums[i] < 0; i++, k--) //用for循环
            nums[i] = -nums[i];
            
        for (int& x : nums) {
            res += x;
            minm = min(minm, x);
        }
        return res - (k % 2) * 2 * minm; //比上面的简洁
    }
};