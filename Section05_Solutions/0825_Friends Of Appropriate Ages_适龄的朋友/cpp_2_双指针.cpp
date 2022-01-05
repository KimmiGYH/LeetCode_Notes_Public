class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int n = ages.size(), res = 0;
        for (int k = 0, i = 0, j = 0; k < n; k++) {
            while (i < k && !check(ages[i], ages[k])) i++;
            if (j < k) j = k;
            while (j < n && check(ages[j], ages[k])) j++;
            if (j > i) res += j - i - 1;
        }
        return res;
    }
    
    bool check(int x, int y) {
        if (y <= 0.5 * x + 7) return false;
        if (y > x) return false;
        return true;
    }
};