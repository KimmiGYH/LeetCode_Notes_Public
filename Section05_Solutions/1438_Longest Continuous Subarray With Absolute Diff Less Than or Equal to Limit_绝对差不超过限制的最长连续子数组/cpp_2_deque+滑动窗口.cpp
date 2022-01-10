class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxq, minq;
        int res = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            while (!minq.empty() && minq.back() > nums[r])
                minq.pop_back();
            while (!maxq.empty() && maxq.back() < nums[r])
                maxq.pop_back();
            minq.push_back(nums[r]);
            maxq.push_back(nums[r]);
            while (maxq.front() - minq.front() > limit) {
                if (maxq.front() == nums[l]) maxq.pop_front();
                if (minq.front() == nums[l]) minq.pop_front();
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};