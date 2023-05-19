class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> stk;
        vector<int> vec(n), res;
        unordered_map<int, int> hash;
        for (int i = n - 1; i >= 0; i--) {
            int x = nums2[i];
            while (stk.size() && x >= stk.top()) stk.pop();
            if (stk.empty()) vec[i] = -1;
            else vec[i] = stk.top();
            stk.push(x);
        }
        for (int i = 0; i < n; i++)
            hash[nums2[i]] = i;
        for (int& x : nums1)
            res.push_back(vec[hash[x]]);
        return res;
    }
};