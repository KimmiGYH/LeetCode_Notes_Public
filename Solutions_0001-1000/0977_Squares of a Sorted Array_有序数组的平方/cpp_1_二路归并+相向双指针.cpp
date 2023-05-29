class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        for (int i = 0, j = n - 1, k = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                res[k] = nums[i] * nums[i];
                i ++, k --;
            } else {
                res[k] = nums[j] * nums[j];
                j --, k --;
            }
        }
        return res;
    }
};

// -----------2023年5月29日----------------

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0, j = nums.size() - 1; i <= j;) {
            if (abs(nums[i]) <= nums[j]) {
                res[n - 1] = nums[j] * nums[j];
                n--; j--;
            } else {
                res[n - 1] = nums[i] * nums[i];
                n--; i++;
            }
        }
        return res;
    }
};