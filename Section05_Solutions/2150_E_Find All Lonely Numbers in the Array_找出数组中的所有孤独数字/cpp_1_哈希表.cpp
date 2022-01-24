class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int& x : nums) hash[x]++;
        for (int& x : nums) {
            int t1 = x + 1, t2 = x - 1;
            if (hash[x] == 1 && !hash.count(t1) && !hash.count(t2) )
                res.push_back(x);
        }
        return res;
    }
};