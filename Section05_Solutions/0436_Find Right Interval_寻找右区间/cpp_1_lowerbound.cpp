#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {        
        int n = intervals.size();
        map<int, int> m;
        // 利用关联数组 map 有序，key存储左端点值，value存储下标index
        for (int i = 0; i < n; ++i) m[intervals[i][0]] = i;
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            // 找每个区间的右端点，在所有左端点里的位置，找到大于等于右端点的第一个
            auto it = m.lower_bound(intervals[i][1]);
            if (it != m.end()) res[i] = it->second;
        }
        return res;
    }
};

/* lowerbound 的用法：搜索首个不小于 i 的元素
auto lower = std::lower_bound(data.begin(), data.end(), i);
*/