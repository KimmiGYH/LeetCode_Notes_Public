#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed[0] == 0)  flowerbed.insert(flowerbed.begin(), 0);
        if (flowerbed.back() == 0) flowerbed.push_back(0);
        int len = flowerbed.size(), cnt = 0, slots = 0;
        for (int i = 0; i <= len; i++) {
            // 分段讨论 eg: [1,0,1,0,1,0,1]
            if (i < len && flowerbed[i] == 0) cnt++;
            else {
                slots += (cnt - 1) / 2;
                cnt = 0;
            }
        }
        return slots >= n;
    }
};