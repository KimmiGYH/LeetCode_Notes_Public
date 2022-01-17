class Solution {
public:
    bool check(int& m, int& D, vector<int>& weights) {
        int tot = 0, cnt = 1;
        for (int& w : weights) {
            if (tot + w > m) {
                tot = 0;
                cnt++;
            }
            tot += w;
        }
        return cnt <= D;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int mx = *max_element(weights.begin(), weights.end());
        int l = mx, r = mx * weights.size();
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, days, weights)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};