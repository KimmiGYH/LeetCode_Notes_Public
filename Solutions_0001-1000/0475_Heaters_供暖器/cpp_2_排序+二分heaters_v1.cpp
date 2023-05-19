class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int m = houses.size(), n = heaters.size(), res = 0;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        for (int& house : houses) {
            int l = 0, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (heaters[mid] >= house) r = mid;
                else l = mid + 1;
            }
            //这里的r是二分出来的index
            int dist1 = (r >= n) ? INT_MAX : heaters[r] - house;
            int dist2 = (r == 0) ? INT_MAX : house - heaters[r-1];
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};