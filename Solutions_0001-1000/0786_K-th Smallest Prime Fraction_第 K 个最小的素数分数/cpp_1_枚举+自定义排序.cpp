class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<int, int>> frac;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                frac.emplace_back(arr[i], arr[j]); // fra.emplace_back(a, b);
            }
        }
        sort(frac.begin(), frac.end(), [&](const auto& x, const auto& y) {
            return x.first * y.second < x.second * y.first;
        });
        return {frac[k - 1].first, frac[k - 1].second};
    }
};

// ------------------------------------------------------------------------

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        vector<pair<int, int>> frac;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                frac.push_back({arr[i], arr[j]}); // frac.push_back({a, b});
            }
        }
        sort(frac.begin(), frac.end(), [&](const auto& x, const auto& y) {
            return x.first * y.second < x.second * y.first;
        });
        return {frac[k - 1].first, frac[k - 1].second};
    }
};