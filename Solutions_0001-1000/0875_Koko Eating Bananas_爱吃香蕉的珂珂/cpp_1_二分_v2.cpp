#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + r >> 1, h = 0;
            // for (int p : piles) {
            //     if (p % mid == 0) h += p/mid;
            //     else h += p/mid + 1;
            // }
            for (int p : piles) h += (p + mid - 1) / mid;
            if (h <= H) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};