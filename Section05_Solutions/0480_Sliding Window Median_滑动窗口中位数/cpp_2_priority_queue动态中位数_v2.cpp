class Solution {
public:
    using LL = long long;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int> > upper;
    unordered_map<int, int> hash;
    
    double get(int& k) {
        if (k % 2) return lower.top();
        else return ((double)lower.top() + upper.top()) / 2;
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
            lower.push(nums[i]);
        for (int i = 0; i < k / 2; i++) {
            upper.push(lower.top());
            lower.pop();
        }
        vector<double> res{get(k)};
        for (int i = k; i < nums.size(); i++) {
            int balance = 0;
            int left = nums[i - k];
            hash[left]++;
            
            if (!lower.empty() && left <= lower.top()) balance--;
            else balance++;
            
            if (!lower.empty() && nums[i] <= lower.top()) {
                lower.push(nums[i]);
                balance++;
            } else {
                upper.push(nums[i]);
                balance--;
            }
            
            if (balance > 0) {
                upper.push(lower.top());
                lower.pop();
            }
            if (balance < 0) {
                lower.push(upper.top());
                upper.pop();
            }
            
            while (!lower.empty() && hash[lower.top()] > 0) {
                hash[lower.top()]--;
                lower.pop();
            }
            while (!upper.empty() && hash[upper.top()] > 0) {
                hash[upper.top()]--;
                upper.pop();
            }
            res.push_back(get(k));
        }
        return res;
    }
};