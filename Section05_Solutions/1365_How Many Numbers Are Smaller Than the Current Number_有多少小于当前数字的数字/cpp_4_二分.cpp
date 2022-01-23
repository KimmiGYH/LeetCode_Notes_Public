class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec(nums);
        vector<int> res;
        int n = nums.size();
        sort(vec.begin(), vec.end());
        for (int& x : nums) {
            if (x == vec[0]) {
                res.push_back(0);
                continue;
            }
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (vec[mid] < x) l = mid;
                else r = mid - 1;
            }
            res.push_back(l + 1);
        }
        return res;
    }
};