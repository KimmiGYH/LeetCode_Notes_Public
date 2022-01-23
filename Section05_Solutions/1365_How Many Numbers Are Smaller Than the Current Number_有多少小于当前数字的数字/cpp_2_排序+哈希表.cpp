class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(nums);
        vector<int> res;
        unordered_map<int, int> hash;
        sort(vec.begin(), vec.end());
        for (int i = n - 1; i >= 0; i--)
            hash[vec[i]] = i;
        for (int& x : nums)
            res.push_back(hash[x]);
        return res;
    }
};
// -------------也可以用数组映射-----------------

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(nums);
        vector<int> res;
        int hash[101];
        sort(vec.begin(), vec.end());
        for (int i = n - 1; i >= 0; i--)
            hash[vec[i]] = i;
        for (int& x : nums)
            res.push_back(hash[x]);
        return res;
    }
};