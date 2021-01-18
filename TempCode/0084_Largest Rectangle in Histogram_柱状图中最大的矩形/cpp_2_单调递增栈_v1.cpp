#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = 0;
        heights.push_back(0);
        // 为了算法书写方便，在数组末尾添加高度 0
        
        stack<int> stk;
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i])
            {
                int cur = stk.top(); stk.pop();
                
                if (stk.empty())
                    res = max(res, heights[cur] * i);
                else
                    res = max(res, heights[cur] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        return res;
    }
};