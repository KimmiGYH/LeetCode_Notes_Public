class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        int s[121] = {0};
        for (int i =0; i < n; i++)
            s[ages[i]]++;
        int res = n * n;
        for (int i = 1; i <= 120; i++)
            for (int j = 1; j <= 120; j++)
                if (j <= 0.5 * i + 7 || j > i)
                    res -= s[i] * s[j];
                else if (i == j)
                    res -= s[i];
        return res;
    }
};