class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = n - 1; i >= 0; i--) { //最长边逆序
            for (int j = i - 1, k = 0; k < j; j--) {
                while (k < j && nums[k] <= nums[i] - nums[j]) k++;
                res += j - k;
            }
        }
        return res;
    }
};

// ---------------------------------------------------------

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) { // 最长边正序
            for (int j = i - 1, k = 0; k < j; j--) {
                while (k < j && nums[k] <= nums[i] - nums[j]) k++;
                res += j - k;
            }
        }
        return res;
    }
};