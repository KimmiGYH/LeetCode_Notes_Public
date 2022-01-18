class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)    s.erase(s.find(nums[i - (k + 1)]));
            auto it = s.insert(nums[i]);
            if (it != s.begin() && *it - *prev(it) <= t)     return true;
            if (next(it) != s.end() && *next(it) - *it <= t) return true;
        }
        return false;
    }
};
// https://zxi.mytechroad.com/blog/hashtable/leetcode-220-contains-duplicate-iii/