class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res = 0, n = customers.size(), x = minutes;
        for (int i = 0, sum = 0; i < n; i++) {
            sum += grumpy[i] * customers[i];
            if (i >= x)
                sum -= grumpy[i-x] * customers[i-x];
            res = max(res, sum);
        }
        for (int i = 0; i < n; i++)
            res += !grumpy[i] * customers[i];
        
        return res;
    }
};