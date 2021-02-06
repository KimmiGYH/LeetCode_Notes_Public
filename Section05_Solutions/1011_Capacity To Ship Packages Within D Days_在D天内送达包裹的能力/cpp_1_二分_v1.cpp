#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int mx = *max_element(weights.begin(), weights.end());
        int l = mx, r = mx * weights.size() / D;
        while (l < r) {
            int mid = l + r >> 1;
            if (cnt_days(weights, mid) <= D) r = mid; // mid运载能力
            else l = mid + 1;
        }
        return l;
    }
    
    int cnt_days(vector<int>& weights, int K) { // K运载能力
        int total = 0, cnt = 1;
        for (int& w : weights) {
            if (total + w > K) {
                total = 0;
                ++cnt;
            }
            total += w;
        }
        return cnt;
    }
};