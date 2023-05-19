class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, sum = 0, mx = 0;
        int n = customers.size();

        for (int i = 0; i < n; i++)
            if (grumpy[i] == 0) {
                res += customers[i];
                customers[i] = 0;
            }
        for (int i = 0, j = 0; j < n; j++) {
            sum += customers[j];
            if (j - i + 1 > minutes) sum -= customers[i++];
            mx = max(mx, sum);
        }

        return res + mx;
    }
};