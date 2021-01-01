#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size(), slots = 0;
        for (int i = 0; i < len; i++)
            if (flowerbed[i] == 0) {
                if ((i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0)) {
                    flowerbed[i] = 1;
                    slots++;
                }
            }
        return slots >= n;
    }
};