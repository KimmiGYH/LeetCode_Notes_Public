#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};

// -------------2023年6月2日-----------------

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // 过期
            if (!q.empty() && i - q.front() + 1 > k)
                q.pop_front();
            
            // nums[i] 比最后一个元素更大
            while (!q.empty() && nums[i] > nums[q.back()])
                q.pop_back();
            
            q.push_back(i);
            
            if (i + 1 >= k)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};