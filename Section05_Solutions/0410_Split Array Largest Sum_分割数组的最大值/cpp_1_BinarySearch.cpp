#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = INT_MAX;
        while (l < r) {
            int mid = (long long) l + r >> 1;
            if (check(nums, m, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
    
    bool check(vector<int>& nums, int& m, int& mid) {
        int sum = 0, cnt = 1; // sum 表示这段的和，cnt 表示段数
        for (auto x : nums) {
            if (x > mid) return false;
            if (sum + x > mid) {
                cnt ++;
                sum = x;
            } else {
                sum += x;
            }
        }
        return cnt <= m;
    }
};