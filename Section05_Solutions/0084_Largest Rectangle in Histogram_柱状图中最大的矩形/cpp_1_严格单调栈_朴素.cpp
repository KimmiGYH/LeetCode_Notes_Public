#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // 每个数的左边第一个比它小的数
        vector<int> left(n), right(n);
        stack<int> stk;
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i])  stk.pop();
            if (stk.empty()) left[i] = -1;
            else  left[i] = stk.top();
            stk.push(i);
        }
        
        stk = stack<int>(); // 记得要清空栈
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty())  right[i] = n;
            else  right[i] = stk.top();
            stk.push(i);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        
        return res;
    }
};