class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // [0, nums.size()-2]
        // (-1, nums.size()-1) 开区间
        int l = -1 , r = nums.size() - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[mid+1]) r = mid;
            else l = mid;
        }
        return r;
    }
};