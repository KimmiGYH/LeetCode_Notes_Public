class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m = houses.size(), n = heaters.size(), res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        for (int i = 0, j = 0; i < m; i++) {
            while (j < n-1 && abs(heaters[j+1] - houses[i]) <= abs(heaters[j] - houses[i]))
                j++;
            res = max(res, abs(heaters[j] - houses[i]));
        }
        return res;
    }
};