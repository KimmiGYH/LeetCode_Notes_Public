class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), len = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.begin() + len, 0);
        int res = sum;
        for (int i = len; i < n; i++) {
            sum += cardPoints[i] - cardPoints[i - len];
            res = min(res, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - res;
    }
};