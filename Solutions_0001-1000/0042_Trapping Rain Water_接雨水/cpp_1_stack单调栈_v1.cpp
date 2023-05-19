#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), res = 0;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                int last = stk.top(); stk.pop();
                if (stk.empty()) break;
                res += (i - stk.top() - 1) 
                        * (min(height[stk.top()], height[i]) - height[last]);
            }
            stk.push(i);
        }
        return res;
    }
};