#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            int last = 0; // 栈里上个柱子的高度
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                res += (height[stk.top()] - last) * (i - stk.top() - 1);
                last = height[stk.top()];
                stk.pop();
            }
            
            if (!stk.empty())
                res += (i - stk.top() - 1) * (height[i] - last);
            
            stk.push(i);
        }
        return res;
    }
};