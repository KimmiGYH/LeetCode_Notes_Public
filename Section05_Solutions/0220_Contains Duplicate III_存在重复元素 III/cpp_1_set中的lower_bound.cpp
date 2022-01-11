#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        typedef long long LL;
        multiset<LL> S;
        // 为了防止出现找不到的情况，加两个哨兵
        S.insert(1e18), S.insert(-1e18);
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (i - j > k)  S.erase(S.find(nums[j++])); // 只是删掉一个迭代器，删完之后j++
            int x = nums[i];
            auto it = S.lower_bound(x);
            if (*it - x <= t)  return true;
            --it; // 找到小于x的最大数
            if (x - *it <= t)  return true;
            S.insert(x);
        }
        return false;
    }
};

// -----------------------------

*lower_bound(nums[i]) - nums[i] <= t
--it;
nums[i] - *lower_bound(nums[i]) <= t
即
nums[i] - t <= *lower_bound(nums[i]) <= nums[i] + t

等价于

*lower_bound(nums[i] - t) <= nums[i] + t