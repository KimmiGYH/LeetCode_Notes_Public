class Solution {
public:
    bool check(vector<int>& sweetness, int& k, int maxsweet) {
        int tot = 0, sum = 0;
        for (int& x : sweetness) {
            sum += x;
            if (sum >= maxsweet) {
                tot++;
                sum = 0;
            }
        }
        if (tot >= k + 1) return true;
        return false;
    }

    int maximizeSweetness(vector<int>& sweetness, int k) {
        int l = *min_element(sweetness.begin(), sweetness.end());
        int r = accumulate(sweetness.begin(), sweetness.end(), 0);
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(sweetness, k, mid)) l = mid;//如果块数较多，可减少块数增加甜度
            else r = mid - 1;
        }
        return r;
    }
};