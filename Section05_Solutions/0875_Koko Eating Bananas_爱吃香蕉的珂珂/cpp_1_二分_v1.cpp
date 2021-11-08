#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + r >> 1;
            if (eatTime(piles, mid) <= H) r = mid; //耗时少吃速过快，要降速；速度足够快
            else l = mid + 1;
        }
        return l;
    }
    
    int eatTime(vector<int>& piles, int K) { // K是速度
        int h = 0;
        for (auto p : piles) {
            // if (p % K == 0) h += p/K;
            // else h += p/K + 1;
            
            h += (p + K - 1) / K; // 还可以写一行里，上取整可以这样写
        }
        return h;
    }    
};