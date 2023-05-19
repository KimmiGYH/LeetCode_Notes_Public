class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> hash;
        for (vector<int>& w : wall) {
            for (int i = 0, sum = 0; i < w.size() - 1; i++) {
                sum += w[i];
                hash[sum]++;
            }
        }
        int seams = 0;
        for (auto& [k, v] : hash)
            seams = max(seams, v);
        return wall.size() - seams;
    }
};