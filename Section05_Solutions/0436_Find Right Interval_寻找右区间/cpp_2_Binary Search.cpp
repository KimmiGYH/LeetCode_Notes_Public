
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    输入：[[3,4], [2,3], [1,2]]
    输出：[-1, 0, 1]    
    intervals[i][左端点，右端点，下标i]
    */
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; ++i) intervals[i].push_back(i);
        sort(intervals.begin(),intervals.end());
        vector<int> res(n, -1);
        for (auto& inner : intervals) {
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                // 在所有左端点里的位置，找到大于等于右端点的第一个
                if (intervals[mid][0] >= inner[1]) r = mid;
                else l = mid + 1;
            }
            if (intervals[r][0] >= inner[1])
                res[inner[2]] = intervals[r][2];
        }
        return res;
    }
};