class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int& y : answers) cnt[y]++;
        for (auto& [y, x] : cnt)
            res += (x + y) / (y + 1) * (y + 1);
        return res;
    }
};