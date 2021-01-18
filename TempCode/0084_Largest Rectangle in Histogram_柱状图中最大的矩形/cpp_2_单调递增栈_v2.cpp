#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), maxArea = 0, prevH, width;
        stack<int> stk; // 单调递增栈，存储下标
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!stk.empty() && heights[stk.top()] > heights[i]) //前面大于后面，遇到下降
            {
                prevH = heights[stk.top()]; stk.pop();
                width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, prevH * width);
            }
            stk.push(i);
        }
        return maxArea;        
    }
};