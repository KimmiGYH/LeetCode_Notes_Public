#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int diff = 0, res = 0;
        for (int i = 1; i < timeSeries.size(); i ++) {
            diff = timeSeries[i] - timeSeries[i - 1];
            res += min(diff, duration);
        }
        if (timeSeries.size()) res += duration;
        return res;
    }
};