class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        for (int k = 0; k < n; ++k) {
            if (nums[i] < nums[k]) i = k;
            if (nums[j] > nums[k]) j = k;
        }
        if (i > j) swap(i, j); //保证 i <= j
        return min({j+1, n-i, i+1+n-j});
    }
};