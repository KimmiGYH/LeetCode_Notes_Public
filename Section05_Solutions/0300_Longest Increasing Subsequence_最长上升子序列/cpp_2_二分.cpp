#include <iostream>
#include <vector>

using namespace std;

/*
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> q;
        for (auto x : nums) {
            if (q.empty() || x > q.back())  q.push_back(x);
            else if (x <= q[0])  q[0] = x;
            else {
                int l = 0, r = q.size() - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (q[mid] < x)  l = mid;
                    else r = mid - 1;
                }
                q[r + 1] = x;
            }
        }
        return q.size();
    }
};