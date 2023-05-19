// 写法一:我自己的写法
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
            hash[nums[i]] ++;
        for (int i = 1; i <= nums.size(); i++) {
            if (hash.count(i) == 0) res[1] = i;
            else hash[i] --;
        }
        for (auto [k, v] : hash) {
            if (hash[k] > 0)
                res[0] = k;
        }
        return res;
    }
};

// 写法二:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        unordered_map<int, int> hash;
        for (int& x : nums)
            hash[x] ++;
        for (int i = 1; i <= nums.size(); i++) {
            if (hash[i] == 2) res[0] = i;
            else if (hash[i] == 0) res[1] = i;
        }
        return res;
    }
};