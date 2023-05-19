class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = (long long)l + r >> 1;
            if (check(mid, houses, heaters)) r = mid;
            else l = mid + 1;
        }
        return r;
    }

    bool check(int radius, vector<int>& houses, vector<int>& heaters) {
        int m = houses.size(), n = heaters.size();
        for (int i = 0, j = 0; i < m; i++) {
            while (j < n && abs(houses[i] - heaters[j]) > radius) j++;
            if (j >= n) return false;
        }
        return true;
    }
};