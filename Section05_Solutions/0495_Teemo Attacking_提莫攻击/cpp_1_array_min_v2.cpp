#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int res = 0;
        for (int i = 1; i < timeSeries.size(); i++) {
            int difference = timeSeries[i] - timeSeries[i - 1];
            res += (difference < duration) ? difference : duration;
        }
        res += duration;
        return res;
    }
};