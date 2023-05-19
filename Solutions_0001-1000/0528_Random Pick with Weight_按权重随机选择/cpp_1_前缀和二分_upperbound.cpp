class Solution {
public:
    vector<int> presum;
    Solution(vector<int>& w) {
        presum = w;
        for (int i = 1; i < w.size(); ++i)
            presum[i] += presum[i - 1];        
    }
    
    int pickIndex() {
        int x = rand() % presum.back();
        auto it = upper_bound(presum.begin(), presum.end(), x);
        int res = it - presum.begin();
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */