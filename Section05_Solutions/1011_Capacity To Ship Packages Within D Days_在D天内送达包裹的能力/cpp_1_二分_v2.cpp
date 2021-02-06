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
            int total = 0, cnt = 1;
            for (int i = 0; i < weights.size(); total += weights[i++])
                if (total + weights[i] > mid) // mid运载能力
                    total = 0, ++cnt;
            if (cnt <= D) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};