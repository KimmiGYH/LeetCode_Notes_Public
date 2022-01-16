class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0, m = houses.size();
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < m; i++) {
            //找到位置 ≥houses[i] 的最小的heaters的迭代器/位置
            auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
            int radius = INT_MAX;
            //如果存在这样的位置，更新半径
            if (larger != heaters.end())
                radius = *larger - houses[i];
            //如果位置不是heaters的首位置而是其他位置，那么前一个heater就是位置小于house[i]的最靠近的heater
            if (larger != heaters.begin()) {
                auto smaller = larger - 1;
                radius = min(radius, houses[i] - *smaller);
            }
            res = max(res, radius);
        }
        return res;
    }
};