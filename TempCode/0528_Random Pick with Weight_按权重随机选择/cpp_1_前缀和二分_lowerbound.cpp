class Solution {
public:
    vector<int> presum;
    Solution(vector<int>& w) {
        presum = w;
        for (int i = 1; i < w.size(); ++i)
            presum[i] += presum[i - 1];        
    }
    
    int pickIndex() {
        int x = rand() % presum.back() + 1;
        return lower_bound(presum.begin(), presum.end(), x) - presum.begin();        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */