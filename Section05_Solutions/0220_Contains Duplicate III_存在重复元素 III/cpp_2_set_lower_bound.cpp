#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long long LL;
        set<LL> record;
        
        for (int i = 0; i < nums.size(); i++) {
            // if (record.find(nums[i]) != record.end())
            //     return true;
            if (record.lower_bound((LL)nums[i] - (LL)t) != record.end() && 
                *record.lower_bound((LL)nums[i] - (LL)t) <= (LL)nums[i] + (LL)t)
                return true;


            record.insert(nums[i]);

            // 保持 record 中最多有 k 个元素
            if (record.size() == k + 1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};