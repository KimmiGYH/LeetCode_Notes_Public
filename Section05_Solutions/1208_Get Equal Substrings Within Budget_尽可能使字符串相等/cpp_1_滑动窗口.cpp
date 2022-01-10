class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum = 0, res = 0, n = s.size();
        for (int i = 0, j = 0; j < n; j++) {
            sum += abs(t[j] - s[j]);
            if (sum > maxCost) {
                sum -= abs(t[i] - s[i]);
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

// ------------------------------------------------------

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum = 0, res = 0, n = s.size();
        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            nums[j] = abs(t[j] - s[j]);
        }
        for (int i = 0, j = 0; j < n; j++) {
            sum += nums[j];
            if (sum > maxCost) {
                sum -= nums[i];
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};