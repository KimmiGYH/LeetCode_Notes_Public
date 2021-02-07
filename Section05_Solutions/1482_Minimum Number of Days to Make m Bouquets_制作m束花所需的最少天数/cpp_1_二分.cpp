#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m*k) return -1;
        
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, bloomDay, m, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    
    // 要验证第 day 天的时候，bloomDay 数组中是不是有 m 个连续的 k 滑窗
    bool check(int day, vector<int>& bloomDay, int& m, int& k) {
        int consecutive = 0, bouquets = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] > day) consecutive = 0;
            else {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;                    
                }
            }
        }
        return bouquets >= m;
    }
};