class Solution {
public:
    using LL = long long;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int> > upper;
    unordered_map<int, int> hash;
    
    double get_median(int& k) {
        if (k % 2) return upper.top();
        else return ((double)lower.top() + upper.top()) / 2;
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++)
            upper.push(nums[i]);
        for (int i = 0; i < k / 2; i++) {//认为规定upper的数量多1
            lower.push(upper.top());
            upper.pop();
        }
        vector<double> res{get_median(k)};
        
        for (int i = k; i < nums.size(); i++) {
            int balance = 0;
            int x = nums[i], y = nums[i - k];// x是加入的数，y是删除的数
            hash[y]++;
            
            if (!upper.empty() && x >= upper.top()) {
                upper.push(x);
                balance++;
            } else {
                lower.push(x);
                balance--;
            }
            
            if (!upper.empty() && y >= upper.top()) 
                balance--;
            else
                balance++;
            
            if (balance > 0) {
                lower.push(upper.top());
                upper.pop();
            }
            if (balance < 0) {
                upper.push(lower.top());
                lower.pop();
            }
            
            while (!upper.empty() && hash[upper.top()] > 0) {
                hash[upper.top()]--;
                upper.pop();
            }
            while (!lower.empty() && hash[lower.top()] > 0) {
                hash[lower.top()]--;
                lower.pop();
            }
            
            res.push_back(get_median(k));
        }
        return res;
    }
};