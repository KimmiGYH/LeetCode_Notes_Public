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
        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && intervals[j][0] < intervals[i][1]) {
                j ++; //如果新区间左端点小于上个区间的右端点，则跳过该区间，并移除
                cnt ++;
            }
            i = j;
        }
        return cnt;
    }
};