#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n < 2) return 0;

        sort(intervals.begin(), intervals.end(), cmp);

        int cnt = 0; //表示需要移除区间的最小数量
        int prev_r = intervals[0][1]; //维护上一个选择区间的右端点
        for(int i = 1; i < n; ++i){
            if(intervals[i][0] < prev_r)  ++cnt; //一个区间的start小于上个区间的end，那么一定是重复区间
            else prev_r = intervals[i][1];
        }
        return cnt;
    }
};