class Solution {
    using LL = long long;
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<LL> rec; //写成 set<LL> rec; 也可以
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (rec.lower_bound(x - (LL)t) != rec.end() &&
               *rec.lower_bound(x - (LL) t) <= x + (LL)t)
                return true;
            
            rec.insert(x);

            // 保持 record 中最多有 k 个元素
            if (rec.size() == k + 1)
                rec.erase(nums[i - k]);
        }
        return false;
    }
};