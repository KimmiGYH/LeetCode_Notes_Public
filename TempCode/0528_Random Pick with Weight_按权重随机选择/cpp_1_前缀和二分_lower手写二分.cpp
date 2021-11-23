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
        int l = 0, r = presum.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (presum[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */