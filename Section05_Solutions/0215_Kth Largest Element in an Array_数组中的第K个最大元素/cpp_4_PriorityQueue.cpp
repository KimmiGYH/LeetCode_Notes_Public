#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end()); //小根堆
        for (int i = 0; i < k - 1; ++i) {
            q.pop();
        }
        return q.top();
    }
};