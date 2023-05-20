class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> h1, h2;
        for (int& x : nums1) h1[x]++;
        for (int& x : nums2) h2[x]++;
        // for (auto item : h1) {
        //     if (h2.count(item.first))
        //         res.push_back(item.first);
        // }
        for (auto [k, v] : h1) {
            if (h2.count(k))
                res.push_back(k);
        }
        return res;
    }
};