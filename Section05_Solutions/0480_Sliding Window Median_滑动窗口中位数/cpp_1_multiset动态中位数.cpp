#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    
    int k;
    multiset<int> left, right;
      
    vector<double> medianSlidingWindow(vector<int>& nums, int _k) {
        k = _k;
        for (int i = 0; i < k; i++)  right.insert(nums[i]);
        for (int i = 0; i < k / 2; i++) { // 人为规定右边多一个元素
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        vector<double> res;
        res.push_back(get_median());
        
        // 滑动窗口
        for (int i = k; i < nums.size(); i++) {
            int x = nums[i], y = nums[i - k]; // x是加入的数，y是删除的数
            
            if (x >= *right.begin()) right.insert(x);
            else left.insert(x);
            
            if (y >= *right.begin())  right.erase(right.find(y));
            else left.erase(left.find(y));
            
            while (left.size() > right.size()) { //如果左边比右边多，那么将左边最大值插到右边去
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }
            while (right.size() > left.size() + 1) { //如果右边比左边多，那么将右边最小值插到左边去
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            res.push_back(get_median());
        }
        return res;
    }

    
    double get_median() {
        if (k % 2) return *right.begin();
        return ((double)*left.rbegin() + *right.begin()) / 2;
    }
};