class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s1, s2;
        for (int& x : nums1) s1.insert(x);
        for (int& x : nums2) s2.insert(x);
        for (auto it = s1.begin(); it != s1.end(); it++) {
            if (s2.count(*it))
                res.push_back(*it);
        }
        return res;
    }
};