class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = n / 2;
        unordered_map<int, int> freq;
        for (int& x : nums) {
            freq[x] ++;
            if (freq[x] > cnt)
                return x;
        }
        return -1;
    }
};

//time: O(n), space: O(n)