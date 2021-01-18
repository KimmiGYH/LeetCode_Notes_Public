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
                // cout << "stk.top: " << stk.top() << endl;
                stk.pop();
                // cout << "resA: " << res << endl;
            }
            
            if (!stk.empty()) {
                res += (i - stk.top() - 1) * (height[i] - last);
                // cout << "resB: " << res << endl;
            }
            
            stk.push(i);
        }
        return res;
    }
};