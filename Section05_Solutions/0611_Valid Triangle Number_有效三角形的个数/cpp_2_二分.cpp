class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j < i && j > 0; j--) {
                int l = 0, r = j - 1;
                while (l < r) {
                    int mid = l + r >> 1;
                    if (nums[mid] + nums[j] > nums[i]) r = mid;
                    else l = mid + 1;
                }
                if (nums[r] + nums[j] > nums[i]) res += j - r;
            }
        }
        return res;
    }
};
