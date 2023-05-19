class Solution {
public:
    bool check(vector<int>& buckets, int& loss, double m) {
        int percentage = 100 - loss;
        double remain = 0, need = 0;
        for (int& bucket : buckets) {
            if (bucket >= m)
                remain += bucket - m;
            else
                need += m - bucket;
        }
        return need <= remain * percentage / 100;
    }

    double equalizeWater(vector<int>& buckets, int loss) {
        int n = buckets.size();
        double eps = 1e-5;
        double l = 0;
        double r = accumulate(buckets.begin(), buckets.end(), 0.0) / n;
        while (r - l >= eps) {
            double mid = (l + r) / 2;
            if (check(buckets, loss, mid)) l = mid;
            else r = mid;
        }
        return r;
    }
};