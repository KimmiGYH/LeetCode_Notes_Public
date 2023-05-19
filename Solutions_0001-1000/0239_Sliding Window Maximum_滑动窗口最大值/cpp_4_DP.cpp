#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        int left = nums[0], right = nums[n - 1];
        for (int i = 0; i < n; ++i) {
            left = i % k == 0 ? nums[i] : max(left, nums[i]);
            leftMax[i] = left;
        }
        for (int i = n - 1; i >= 0; --i) {
            right = i == n - 1 || (i + 1) % k == 0 ? nums[i] : max(right, nums[i]);
            rightMax[i] = right;
        }
        vector<int> res(n - k + 1);
        for (int i = 0; i < res.size(); ++i) {
            res[i] = (max(leftMax[i + k - 1], rightMax[i]));
        }
        return res;
    }
};