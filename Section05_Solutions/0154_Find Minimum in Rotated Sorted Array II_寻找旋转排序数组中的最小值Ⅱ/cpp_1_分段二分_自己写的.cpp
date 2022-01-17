class Solution {
public:
    int findMin(vector<int>& nums) {
        int R = nums.size() - 1;
        while (R > 0 && nums[R] == nums[0]) R--;
        // if (R == 0) return nums[0];
        if (nums[R] > nums[0]) return nums[0];

        int l = 0, r = R;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] < nums[0]) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};