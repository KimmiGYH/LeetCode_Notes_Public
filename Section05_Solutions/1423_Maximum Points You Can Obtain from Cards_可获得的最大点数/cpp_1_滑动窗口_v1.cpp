class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), res = INT_MAX, len = n - k, tot = 0;
        for (int& p : cardPoints) tot += p;
        for (int i = 0, j = 0, sum = 0; j < n; j ++) {
            sum += cardPoints[j];
            if (j - i + 1 > len) sum -= cardPoints[i++];
            if (j >= len - 1) res = min(res, sum);
        }
        return tot - res;
    }
};
